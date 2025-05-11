; ModuleID = 'generated'
source_filename = "generated"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-n32:64-S128-Fn32"
target triple = "arm64-apple-darwin23.4.0"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define i32 @main() {
entry:
  %retval = alloca i32, align 4
  %max = alloca i32, align 4
  store i32 2, ptr %max, align 4
  %loaded_from_var = load i32, ptr %max, align 4
  store i32 %loaded_from_var, ptr %max, align 4
  %x = alloca i32, align 4
  store i32 10, ptr %x, align 4
  %loaded_from_var1 = load i32, ptr %x, align 4
  store i32 %loaded_from_var1, ptr %x, align 4
  %y = alloca i32, align 4
  store i32 20, ptr %y, align 4
  %loaded_from_var2 = load i32, ptr %y, align 4
  store i32 %loaded_from_var2, ptr %y, align 4
  %loaded_cond = load i32, ptr %y, align 4
  %cond_bool = icmp ne i32 %loaded_cond, 0
  br i1 %cond_bool, label %ternary.true, label %ternary.false

ternary.true:                                     ; preds = %entry
  br label %ternary.merge

ternary.false:                                    ; preds = %entry
  br label %ternary.merge

ternary.merge:                                    ; preds = %ternary.false, %ternary.true
  %ternarytmp = phi ptr [ %x, %ternary.true ], [ %y, %ternary.false ]
  %loaded_lhs = load i32, ptr %x, align 4
  %loaded_rhs = load i32, ptr %ternarytmp, align 4
  %gttmp = icmp sgt i32 %loaded_lhs, %loaded_rhs
  %select_result = select i1 %gttmp, ptr %x, ptr %y
  %selected_loaded = load i32, ptr %select_result, align 4
  store i32 %selected_loaded, ptr %max, align 4
  %loaded_int = load i32, ptr %max, align 4
  call void (ptr, ...) @printf(ptr @0, i32 %loaded_int)
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret
}

declare void @printf(ptr, ...)
