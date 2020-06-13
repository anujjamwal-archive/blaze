load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "operation-test",
    srcs = glob(["*.cc"]),
    copts = ["-Iinclude"],
    deps = [
        "//include/blaze/operation:operation_api",
        "//src/operation:operation",
        "@gtest//:gtest_main",
    ],
)