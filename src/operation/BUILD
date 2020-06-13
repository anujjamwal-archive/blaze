load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "operation",
  srcs = glob(["*.cc"]),
  visibility = ["//visibility:public"],
  copts = ["-Iinclude"],
  deps = [
    "//include/blaze/operation:operation_api"
  ]
)