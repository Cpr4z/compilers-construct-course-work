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
  %x = alloca i32, align 4
  store i32 2, ptr %x, align 4
  %loaded_from_var = load i32, ptr %x, align 4
  store i32 %loaded_from_var, ptr %x, align 4
  %switch_cond = load i32, ptr %x, align 4
  switch i32 %switch_cond, label %switch.end [
    i32 1, label %case
    i32 2, label %case1
    i32 3, label %case2
  ]

switch.end:                                       ; preds = %case2, %case1, %case, %entry
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret

case:                                             ; preds = %entry
  call void (ptr, ...) @printf(ptr @0, i32 100)
  br label %switch.end

case1:                                            ; preds = %entry
  call void (ptr, ...) @printf(ptr @1, i32 200)
  br label %switch.end

case2:                                            ; preds = %entry
  call void (ptr, ...) @printf(ptr @2, i32 300)
  br label %switch.end
}

declare void @printf(ptr, ...)
