load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "thread",
  srcs = glob(["*.cc"]),
  visibility = ["//visibility:public"],
  copts = ["-Iinclude"],
  deps = [
    "//include/blaze/concur:thread_api",
    "//include/blaze/concur:scheduler_api"
  ]
)