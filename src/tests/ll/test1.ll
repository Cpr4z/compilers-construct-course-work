; ModuleID = 'generated'
source_filename = "generated"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-n32:64-S128-Fn32"
target triple = "arm64-apple-darwin23.4.0"

@0 = private unnamed_addr constant [4 x i8] c"abc\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@3 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@4 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@5 = private unnamed_addr constant [5 x i8] c"abcd\00", align 1
@6 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@7 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@8 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define i32 @main() {
entry:
  %retval = alloca i32, align 4
  %a = alloca i32, align 4
  store i32 9, ptr %a, align 4
  %loaded_from_var = load i32, ptr %a, align 4
  store i32 %loaded_from_var, ptr %a, align 4
  %b = alloca i32, align 4
  store i32 34, ptr %b, align 4
  %loaded_from_var1 = load i32, ptr %b, align 4
  store i32 %loaded_from_var1, ptr %b, align 4
  %loaded_int = load i32, ptr %a, align 4
  call void (ptr, ...) @printf(ptr @1, i32 %loaded_int)
  %loaded_int2 = load i32, ptr %b, align 4
  call void (ptr, ...) @printf(ptr @2, i32 %loaded_int2)
  call void (ptr, ...) @printf(ptr @3, ptr @0)
  call void (ptr, ...) @printf(ptr @4, i32 2)
  call void (ptr, ...) @printf(ptr @6, ptr @5)
  %loaded_int3 = load i32, ptr %a, align 4
  call void (ptr, ...) @printf(ptr @7, i32 %loaded_int3)
  %loaded_int4 = load i32, ptr %b, align 4
  call void (ptr, ...) @printf(ptr @8, i32 %loaded_int4)
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret
}

declare void @printf(ptr, ...)
