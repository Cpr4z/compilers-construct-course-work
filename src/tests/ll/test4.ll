; ModuleID = 'generated'
source_filename = "generated"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-n32:64-S128-Fn32"
target triple = "arm64-apple-darwin23.4.0"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define i32 @main() {
entry:
  %retval = alloca i32, align 4
  %x = alloca i32, align 4
  store i32 1, ptr %x, align 4
  %loaded_from_var = load i32, ptr %x, align 4
  store i32 %loaded_from_var, ptr %x, align 4
  %loadtmp = load i32, ptr %x, align 4
  %inctmp = add i32 %loadtmp, 1
  store i32 %inctmp, ptr %x, align 4
  %loadtmp1 = load i32, ptr %x, align 4
  %inctmp2 = add i32 %loadtmp1, 1
  store i32 %inctmp2, ptr %x, align 4
  %loadtmp3 = load i32, ptr %x, align 4
  %dectmp = sub i32 %loadtmp3, 1
  store i32 %dectmp, ptr %x, align 4
  %loaded_int = load i32, ptr %x, align 4
  call void (ptr, ...) @printf(ptr @0, i32 %loaded_int)
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret
}

declare void @printf(ptr, ...)
