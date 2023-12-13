/**
 * @file progressbar.h
 * @author leoli (jafee201153@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __PROGRESSBAR_H
#define __PROGRESSBAR_H

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
#include <time.h>

#pragma endregion includes

/*  */
#pragma region typedef

typedef struct _statusbar_t {
    unsigned int start_time;
    const char *label;
    int format_index;
    int format_length;
    char *format;
    int last_printed;
} statusbar;
#if !defined(__ARM_ARCH)
typedef struct _progressbar_t {
    /// maximum value
    unsigned long max;
    /// current value
    unsigned long value;

    /// time progressbar was started
    time_t start;

    /// label
    const char *label;

    /// characters for the beginning, filling and end of the
    /// progressbar. E.g. |###    | has |#|
    struct {
        char begin;
        char fill;
        char end;
    } format;
} progressbar;
#endif

#pragma endregion typedef

/*  */
#pragma region defines

#pragma endregion defines

/*  */
#pragma region Exported Functions

/// Create a new statusbar with the specified label and format string
statusbar *statusbar_new_with_format(const char *label, const char *format);

/// Create a new statusbar with the specified label
statusbar *statusbar_new(const char *label);

/// Free an existing progress bar. Don't call this directly; call *statusbar_finish* instead.
void statusbar_free(statusbar *bar);

/// Increment the given statusbar.
void statusbar_inc(statusbar *bar);

/// Finalize (and free!) a statusbar. Call this when you're done.
void statusbar_finish(statusbar *bar);

/// Draw a statusbar to the screen. Don't call this directly,
/// as it's called internally by *statusbar_inc*.
void statusbar_draw(statusbar *bar);

#if !defined(__ARM_ARCH)
/// Create a new progressbar with the specified label and number of steps.
///
/// @param label The label that will prefix the progressbar.
/// @param max The number of times the progressbar must be incremented before it is considered complete,
///            or, in other words, the number of tasks that this progressbar is tracking.
///
/// @return A progressbar configured with the provided arguments. Note that the user is responsible for disposing
///         of the progressbar via progressbar_finish when finished with the object.
progressbar *progressbar_new(const char *label, unsigned long max);

/// Create a new progressbar with the specified label, number of steps, and format string.
///
/// @param label The label that will prefix the progressbar.
/// @param max The number of times the progressbar must be incremented before it is considered complete,
///            or, in other words, the number of tasks that this progressbar is tracking.
/// @param format The format of the progressbar. The string provided must be three characters, and it will
///               be interpreted with the first character as the left border of the bar, the second
///               character of the bar and the third character as the right border of the bar. For example,
///               "<->" would result in a bar formatted like "<------     >".
///
/// @return A progressbar configured with the provided arguments. Note that the user is responsible for disposing
///         of the progressbar via progressbar_finish when finished with the object.
progressbar *progressbar_new_with_format(const char *label, unsigned long max, const char *format);

/// Free an existing progress bar. Don't call this directly; call *progressbar_finish* instead.
void progressbar_free(progressbar *bar);

/// Increment the given progressbar. Don't increment past the initialized # of steps, though.
void progressbar_inc(progressbar *bar);

/// Set the current status on the given progressbar.
void progressbar_update(progressbar *bar, unsigned long value);

/// Set the label of the progressbar. Note that no rendering is done. The label is simply set so that the next
/// rendering will use the new label. To immediately see the new label, call progressbar_draw.
/// Does not update display or copy the label
void progressbar_update_label(progressbar *bar, const char *label);

/// Finalize (and free!) a progressbar. Call this when you're done, or if you break out
/// partway through.
void progressbar_finish(progressbar *bar);
#endif

#pragma endregion Exported Functions

#ifdef __cplusplus
}
#endif

#endif  // __PROGRESSBAR_H
