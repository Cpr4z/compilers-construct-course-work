; ModuleID = 'generated'
source_filename = "generated"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-n32:64-S128-Fn32"
target triple = "arm64-apple-darwin23.4.0"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define i32 @max(i32 %a, i32 %b) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %retval = alloca i32, align 4
  %loaded_cond = load i32, ptr %b2, align 4
  %cond_bool = icmp ne i32 %loaded_cond, 0
  br i1 %cond_bool, label %ternary.true, label %ternary.false

ternary.true:                                     ; preds = %entry
  br label %ternary.merge

ternary.false:                                    ; preds = %entry
  br label %ternary.merge

ternary.merge:                                    ; preds = %ternary.false, %ternary.true
  %ternarytmp = phi ptr [ %a1, %ternary.true ], [ %b2, %ternary.false ]
  %loaded_lhs = load i32, ptr %a1, align 4
  %loaded_rhs = load i32, ptr %ternarytmp, align 4
  %gttmp = icmp sgt i32 %loaded_lhs, %loaded_rhs
  %select_result = select i1 %gttmp, ptr %a1, ptr %b2
  %selected_loaded = load i32, ptr %select_result, align 4
  %result = alloca i32, align 4
  store i32 %selected_loaded, ptr %result, align 4
  %loaded_int = load i32, ptr %a1, align 4
  call void (ptr, ...) @printf(ptr @0, i32 %loaded_int)
  %loaded_int3 = load i32, ptr %b2, align 4
  call void (ptr, ...) @printf(ptr @1, i32 %loaded_int3)
  %loaded_int4 = load i32, ptr %result, align 4
  call void (ptr, ...) @printf(ptr @2, i32 %loaded_int4)
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret
}

define i32 @main() {
entry:
  %retval = alloca i32, align 4
  %calltmp = call i32 @max(i32 10, i32 20)
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret
}

declare void @printf(ptr, ...)
