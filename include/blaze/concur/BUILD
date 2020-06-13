load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "thread_api",
  hdrs = ["thread.hh"],
  visibility = ["//visibility:public"],
  copts = ["-Iinclude"],
  deps = [":scheduler_api"]
)

cc_library(
  name = "scheduler_api",
  hdrs = ["scheduler.hh"],
  visibility = ["//visibility:public"],
  copts = ["-Iinclude"],
)