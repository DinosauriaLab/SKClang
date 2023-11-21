# UtilityClang

目的為適用於嵌入式平台的純 C 語言通用 lib

### Usage

- fork 本專案後，使用以下指令將本專案加入到你的專案中

```shell
git submodule add <url> <path>
```

- 添加下列 `git config` 配置，使 `USER_CODE` 的部分內容不會被 `git` 追蹤

```shell
git config --local filter.gitignore.clean "sed '/\/\/ #USER_CODE_BEGIN/,/\/\/ #USER_CODE_END/{//!d;};/\/\/ #USER_CODE_BEGIN/a\\'"
git config --local filter.gitignore.smudge cat
```

### Appendix

- 更新本專案

```shell
git submodule update --init --recursive
```
