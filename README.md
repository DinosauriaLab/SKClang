# UtilityClang

本專案的目的為創建一個純 C 語言的通用 library，且不依賴任何第三方 lib。並且主要專注於 `ARM Cortex-M` 系列的 MCU 上。

### Features

| Feature          | Description                                                              |
| :--------------- | :----------------------------------------------------------------------- |
| `arm_c`          | 一些 `ARM Cortex-M` 系列的 MCU 上常用的功能                              |
| `debug_c`        | 一些除錯用的功能, 例如輸出以顏色標記的 `ERROR`, `WARNING`, `INFORMATION` |
| `math_c`         | 一些數學運算的功能                                                       |
| `progressbar`    | 一個簡單的使用 `printf` 進行進度條的功能                             |
| `utility_c`      | 一些通用的功能                                                           |
| `utility_config` | 一些通用的配置                                                           |

### Usage

- fork 本專案後，使用以下指令將本專案加入到你的專案中

```shell
git submodule add <url> <path>
```

- 更新本專案

```shell
git submodule update --init --recursive
```

### Appendix

- 添加下列 `git config` 配置，使 `USER_CODE` 的部分內容不會被 `git` 追蹤

```shell
git config --local filter.gitignore.clean "sed '/\/\/ #USER_CODE_BEGIN/,/\/\/ #USER_CODE_END/{//!d;};/\/\/ #USER_CODE_BEGIN/a\\'"
git config --local filter.gitignore.smudge cat
```
