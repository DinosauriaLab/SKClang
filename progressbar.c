/**
 * @file progressbar.c
 * @author leoli (jafee201153@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "progressbar.h"

#ifdef __cplusplus
extern "C" {
#endif

/*  */
#pragma region includes

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if !defines(__ARM_ARCH)
#include <assert.h>
#include <limits.h>
#include <termcap.h> /* tgetent, tgetnum */
#endif

#pragma endregion includes

/*  */
#pragma region typedef

#pragma endregion typedef

/*  */
#pragma region Private Function Prototypes

#pragma endregion Private Function Prototypes

/*  */
#pragma region defines

#pragma endregion defines

/*  */
#pragma region variables

#pragma endregion variables

/*  */
#pragma region External Functions

#pragma endregion External Functions

/*  */
#pragma region Exported Functions

statusbar *statusbar_new_with_format(const char *label, const char *format) {
    statusbar *new = malloc(sizeof(statusbar));
    if (new == NULL) {
        return NULL;
    }

    new->label         = label;
    new->start_time    = time(0);
    new->format_length = strlen(format);
    new->format        = malloc(sizeof(char) * (new->format_length + 1));
    if (new->format == NULL) {
        free(new);
        return NULL;
    }

    strncpy(new->format, format, new->format_length);
    new->format_index = 0;
    new->last_printed = 0;

    return new;
}

statusbar *statusbar_new(const char *label) {
    return statusbar_new_with_format(label, "-\\|/");
}

void statusbar_free(statusbar *bar) {
    // We malloc'd a string, so let's be sure to free it...
    free(bar->format);
    // ...before we free the struct itself.
    free(bar);

    return;
}

void statusbar_inc(statusbar *bar) {
    bar->format_index++;
    if (bar->format_index >= bar->format_length) {
        bar->format_index = 0;
    }
    statusbar_draw(bar);

    return;
}

void statusbar_draw(statusbar *bar) {
    // Erase the last draw.
    fprintf(stderr, "\r");

    bar->last_printed = fprintf(
        stderr,
        "%s: %c",
        bar->label,
        bar->format[bar->format_index]);

    return;
}

void statusbar_finish(statusbar *bar) {
    // Draw one more time, with the actual time to completion.
    unsigned int offset = time(0) - (bar->start_time);

    // Convert the time to display into HHH:MM:SS
    unsigned int h = offset / 3600;
    offset -= h * 3600;
    unsigned int m = offset / 60;
    offset -= m * 60;
    unsigned int s = offset;

    // Erase the last draw
    fprintf(stderr, "\r");

    // Calculate number of spaces for right-justified time to completion
    bar->last_printed = fprintf(stderr, "%s: %3d:%02d:%02d", bar->label, h, m, s);
    fprintf(stderr, "\r");

    // Print right-justified
    fprintf(stderr, "%s: ", bar->label);
    fprintf(stderr, "%*s", 80 - (bar->last_printed), "");
    fprintf(stderr, "%3d:%02d:%02d\n", h, m, s);

    // We've finished with this statusbar, so go ahead and free it.
    statusbar_free(bar);

    return;
}

#if !defines(__ARM_ARCH)
///  How wide we assume the screen is if termcap fails.
enum { DEFAULT_SCREEN_WIDTH = 80 };
/// The smallest that the bar can ever be (not including borders)
enum { MINIMUM_BAR_WIDTH = 10 };
/// The format in which the estimated remaining time will be reported
static const char *const ETA_FORMAT = "ETA:%2dh%02dm%02ds";
/// The maximum number of characters that the ETA_FORMAT can ever yield
enum { ETA_FORMAT_LENGTH = 13 };
/// Amount of screen width taken up by whitespace (i.e. whitespace between label/bar/ETA components)
enum { WHITESPACE_LENGTH = 2 };
/// The amount of width taken up by the border of the bar component.
enum { BAR_BORDER_WIDTH = 2 };

/// Models a duration of time broken into hour/minute/second components. The number of seconds should be less than the
/// number of seconds in one minute, and the number of minutes should be less than the number of minutes in one hour.
typedef struct {
    int hours;
    int minutes;
    int seconds;
} progressbar_time_components;

static void progressbar_draw(const progressbar *bar);

/**
 * Create a new progress bar with the specified label, max number of steps, and format string.
 * Note that `format` must be exactly three characters long, e.g. "<->" to render a progress
 * bar like "<---------->". Returns NULL if there isn't enough memory to allocate a progressbar
 */
progressbar *progressbar_new_with_format(const char *label, unsigned long max, const char *format) {
    progressbar *new = malloc(sizeof(progressbar));
    if (new == NULL) {
        return NULL;
    }

    new->max   = max;
    new->value = 0;
    new->start = time(NULL);
    assert(3 == strlen(format) && "format must be 3 characters in length");
    new->format.begin = format[0];
    new->format.fill  = format[1];
    new->format.end   = format[2];

    progressbar_update_label(new, label);
    progressbar_draw(new);

    return new;
}

/**
 * Create a new progress bar with the specified label and max number of steps.
 */
progressbar *progressbar_new(const char *label, unsigned long max) {
    return progressbar_new_with_format(label, max, "|=|");
}

void progressbar_update_label(progressbar *bar, const char *label) {
    bar->label = label;
}

/**
 * Delete an existing progress bar.
 */
void progressbar_free(progressbar *bar) {
    free(bar);
}

/**
 * Increment an existing progressbar by `value` steps.
 */
void progressbar_update(progressbar *bar, unsigned long value) {
    bar->value = value;
    progressbar_draw(bar);
}

/**
 * Increment an existing progressbar by a single step.
 */
void progressbar_inc(progressbar *bar) {
    progressbar_update(bar, bar->value + 1);
}

static void progressbar_write_char(FILE *file, const int ch, const size_t times) {
    size_t i;
    for (i = 0; i < times; ++i) {
        fputc(ch, file);
    }
}

static int progressbar_max(int x, int y) {
    return x > y ? x : y;
}

static unsigned int get_screen_width(void) {
    char termbuf[2048];
    if (tgetent(termbuf, getenv("TERM")) >= 0) {
        return tgetnum("co") /* -2 */;
    } else {
        return DEFAULT_SCREEN_WIDTH;
    }
}

static int progressbar_bar_width(int screen_width, int label_length) {
    return progressbar_max(MINIMUM_BAR_WIDTH, screen_width - label_length - ETA_FORMAT_LENGTH - WHITESPACE_LENGTH);
}

static int progressbar_label_width(int screen_width, int label_length, int bar_width) {
    int eta_width = ETA_FORMAT_LENGTH;

    // If the progressbar is too wide to fit on the screen, we must sacrifice the label.
    if (label_length + 1 + bar_width + 1 + ETA_FORMAT_LENGTH > screen_width) {
        return progressbar_max(0, screen_width - bar_width - eta_width - WHITESPACE_LENGTH);
    } else {
        return label_length;
    }
}

static int progressbar_remaining_seconds(const progressbar *bar) {
    double offset = difftime(time(NULL), bar->start);
    if (bar->value > 0 && offset > 0) {
        return (offset / (double)bar->value) * (bar->max - bar->value);
    } else {
        return 0;
    }
}

static progressbar_time_components progressbar_calc_time_components(int seconds) {
    int hours = seconds / 3600;
    seconds -= hours * 3600;
    int minutes = seconds / 60;
    seconds -= minutes * 60;

    progressbar_time_components components = {hours, minutes, seconds};
    return components;
}

static void progressbar_draw(const progressbar *bar) {
    int screen_width = get_screen_width();
    int label_length = strlen(bar->label);
    int bar_width    = progressbar_bar_width(screen_width, label_length);
    int label_width  = progressbar_label_width(screen_width, label_length, bar_width);

    int progressbar_completed = (bar->value >= bar->max);
    int bar_piece_count       = bar_width - BAR_BORDER_WIDTH;
    int bar_piece_current     = (progressbar_completed)
                                    ? bar_piece_count
                                    : bar_piece_count * ((double)bar->value / bar->max);

    progressbar_time_components eta = (progressbar_completed)
                                          ? progressbar_calc_time_components(difftime(time(NULL), bar->start))
                                          : progressbar_calc_time_components(progressbar_remaining_seconds(bar));

    if (label_width == 0) {
        // The label would usually have a trailing space, but in the case that we don't print
        // a label, the bar can use that space instead.
        bar_width += 1;
    } else {
        // Draw the label
        fwrite(bar->label, 1, label_width, stderr);
        fputc(' ', stderr);
    }

    // Draw the progressbar
    fputc(bar->format.begin, stderr);
    progressbar_write_char(stderr, bar->format.fill, bar_piece_current);
    progressbar_write_char(stderr, ' ', bar_piece_count - bar_piece_current);
    fputc(bar->format.end, stderr);

    // Draw the ETA
    fputc(' ', stderr);
    fprintf(stderr, ETA_FORMAT, eta.hours, eta.minutes, eta.seconds);
    fputc('\r', stderr);
}

/**
 * Finish a progressbar, indicating 100% completion, and free it.
 */
void progressbar_finish(progressbar *bar) {
    // Make sure we fill the progressbar so things look complete.
    progressbar_draw(bar);

    // Print a newline, so that future outputs to stderr look prettier
    fprintf(stderr, "\n");

    // We've finished with this progressbar, so go ahead and free it.
    progressbar_free(bar);
}
#endif

#pragma endregion Exported Functions

/*  */
#pragma region Private Functions

#pragma endregion Private Functions

#ifdef __cplusplus
}
#endif
