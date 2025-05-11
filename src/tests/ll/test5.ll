; ModuleID = 'generated'
source_filename = "generated"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-n32:64-S128-Fn32"
target triple = "arm64-apple-darwin23.4.0"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define i32 @main() {
entry:
  %retval = alloca i32, align 4
  %n = alloca i32, align 4
  store i32 5, ptr %n, align 4
  %loaded_from_var = load i32, ptr %n, align 4
  store i32 %loaded_from_var, ptr %n, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %loaded_lhs = load i32, ptr %n, align 4
  %netmp = icmp ne i32 %loaded_lhs, 0
  %whilecond = icmp ne i1 %netmp, false
  br i1 %whilecond, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %loaded_int = load i32, ptr %n, align 4
  call void (ptr, ...) @printf(ptr @0, i32 %loaded_int)
  %loadtmp = load i32, ptr %n, align 4
  %dectmp = sub i32 %loadtmp, 1
  store i32 %dectmp, ptr %n, align 4
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %calltmp = call i32 @f(i32 24, i32 42)
  ret i32 0
}

define i32 @f(i32 %s, i32 %y) {
entry:
  %s1 = alloca i32, align 4
  store i32 %s, ptr %s1, align 4
  %y2 = alloca i32, align 4
  store i32 %y, ptr %y2, align 4
  %retval = alloca i32, align 4
  %loaded_int = load i32, ptr %s1, align 4
  call void (ptr, ...) @printf(ptr @1, i32 %loaded_int)
  %loaded_int3 = load i32, ptr %y2, align 4
  call void (ptr, ...) @printf(ptr @2, i32 %loaded_int3)
  ret i32 0
}

declare void @printf(ptr, ...)
