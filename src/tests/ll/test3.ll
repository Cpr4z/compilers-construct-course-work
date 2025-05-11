; ModuleID = 'generated'
source_filename = "generated"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-n32:64-S128-Fn32"
target triple = "arm64-apple-darwin23.4.0"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define i32 @main() {
entry:
  %retval = alloca i32, align 4
  %i = alloca i32, align 4
  store i32 0, ptr %i, align 4
  %loaded_from_var = load i32, ptr %i, align 4
  store i32 %loaded_from_var, ptr %i, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %loaded_lhs = load i32, ptr %i, align 4
  %letmp = icmp sle i32 %loaded_lhs, 10
  %whilecond = icmp ne i1 %letmp, false
  br i1 %whilecond, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %loaded_int = load i32, ptr %i, align 4
  call void (ptr, ...) @printf(ptr @0, i32 %loaded_int)
  %loadtmp = load i32, ptr %i, align 4
  %inctmp = add i32 %loadtmp, 1
  store i32 %inctmp, ptr %i, align 4
  %loadtmp1 = load i32, ptr %i, align 4
  %inctmp2 = add i32 %loadtmp1, 1
  store i32 %inctmp2, ptr %i, align 4
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %j = alloca i32, align 4
  store i32 0, ptr %j, align 4
  %loaded_from_var3 = load i32, ptr %j, align 4
  store i32 %loaded_from_var3, ptr %j, align 4
  br label %while.cond4

while.cond4:                                      ; preds = %while.body5, %while.end
  %loaded_lhs7 = load i32, ptr %j, align 4
  %letmp8 = icmp sle i32 %loaded_lhs7, 10
  %whilecond9 = icmp ne i1 %letmp8, false
  br i1 %whilecond9, label %while.body5, label %while.end6

while.body5:                                      ; preds = %while.cond4
  %loaded_int10 = load i32, ptr %j, align 4
  call void (ptr, ...) @printf(ptr @1, i32 %loaded_int10)
  %loadtmp11 = load i32, ptr %j, align 4
  %inctmp12 = add i32 %loadtmp11, 1
  store i32 %inctmp12, ptr %j, align 4
  br label %while.cond4

while.end6:                                       ; preds = %while.cond4
  %k = alloca i32, align 4
  store i32 0, ptr %k, align 4
  %loaded_from_var13 = load i32, ptr %k, align 4
  store i32 %loaded_from_var13, ptr %k, align 4
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret
}

declare void @printf(ptr, ...)
