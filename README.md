# LeetCode
LeetCode Solutions

nlohmann json and gtest

```
static int x = []() {
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}();
```

```
cd ${SOLUTION_DIR}
ln -s ../utils utils
mkdir build
cd build
rm -rf * && cmake .. && make && ./solution_unittest.out
```