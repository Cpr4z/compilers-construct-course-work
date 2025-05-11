; ModuleID = 'generated'
source_filename = "generated"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-n32:64-S128-Fn32"
target triple = "arm64-apple-darwin23.4.0"

@0 = private unnamed_addr constant [4 x i8] c"Hi!\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@3 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@4 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define i32 @main() {
entry:
  %retval = alloca i32, align 4
  %calltmp = call i32 @Print1()
  %calltmp1 = call i32 @Print2(i32 31415)
  %calltmp2 = call i32 @Print3(i32 777, i32 34)
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret
}

define i32 @Print1() {
entry:
  %retval = alloca i32, align 4
  call void (ptr, ...) @printf(ptr @1, ptr @0)
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret
}

define i32 @Print2(i32 %x) {
entry:
  %x1 = alloca i32, align 4
  store i32 %x, ptr %x1, align 4
  %retval = alloca i32, align 4
  %loaded_int = load i32, ptr %x1, align 4
  call void (ptr, ...) @printf(ptr @2, i32 %loaded_int)
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret
}

define i32 @Print3(i32 %x, i32 %y) {
entry:
  %x1 = alloca i32, align 4
  store i32 %x, ptr %x1, align 4
  %y2 = alloca i32, align 4
  store i32 %y, ptr %y2, align 4
  %retval = alloca i32, align 4
  %loaded_int = load i32, ptr %x1, align 4
  call void (ptr, ...) @printf(ptr @3, i32 %loaded_int)
  %loaded_int3 = load i32, ptr %y2, align 4
  call void (ptr, ...) @printf(ptr @4, i32 %loaded_int3)
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret
}

declare void @printf(ptr, ...)
