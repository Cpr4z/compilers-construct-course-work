; ModuleID = 'generated'
source_filename = "generated"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-n32:64-S128-Fn32"
target triple = "arm64-apple-darwin23.4.0"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@3 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@4 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@5 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define i32 @main() {
entry:
  %retval = alloca i32, align 4
  %a = alloca i32, align 4
  store i32 6, ptr %a, align 4
  %loaded_from_var = load i32, ptr %a, align 4
  store i32 %loaded_from_var, ptr %a, align 4
  %b = alloca i32, align 4
  store i32 1981, ptr %b, align 4
  %loaded_from_var1 = load i32, ptr %b, align 4
  store i32 %loaded_from_var1, ptr %b, align 4
  %calltmp = call i32 @max(ptr %a, ptr %b)
  %tmp = alloca i32, align 4
  store i32 %calltmp, ptr %tmp, align 4
  %calltmp2 = call i32 @max(ptr %a, ptr %b)
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret
}

define i32 @max(i32 %a, i32 %b) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %retval = alloca i32, align 4
  %tmp = alloca i32, align 4
  store i32 0, ptr %tmp, align 4
  %loaded_rhs = load i32, ptr %tmp, align 4
  %loaded_lhs = load i32, ptr %a1, align 4
  %gttmp = icmp sgt i32 %loaded_lhs, %loaded_rhs
  %ifcond = icmp ne i1 %gttmp, false
  br i1 %ifcond, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %tmp3 = alloca i32, align 4
  store i32 1, ptr %tmp3, align 4
  %loaded_int = load i32, ptr %tmp3, align 4
  call void (ptr, ...) @printf(ptr @0, i32 %loaded_int)
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %a4 = alloca i32, align 4
  store i32 3, ptr %a4, align 4
  %loaded_from_var = load i32, ptr %a4, align 4
  store i32 %loaded_from_var, ptr %a4, align 4
  %result = alloca i32, align 4
  %loaded_rhs5 = load i32, ptr %a4, align 4
  store i32 %loaded_rhs5, ptr %result, align 4
  %loaded_int6 = load i32, ptr %result, align 4
  call void (ptr, ...) @printf(ptr @1, i32 %loaded_int6)
  %loaded_int7 = load i32, ptr %a4, align 4
  call void (ptr, ...) @printf(ptr @2, i32 %loaded_int7)
  %ret_val = load i32, ptr %result, align 4
  ret i32 %ret_val

entry8:                                           ; No predecessors!
  %a9 = alloca i32, align 4
  store i32 %a, ptr %a9, align 4
  %b10 = alloca i32, align 4
  store i32 %b, ptr %b10, align 4
  %retval11 = alloca i32, align 4
  %loaded_lhs12 = load i32, ptr %a9, align 4
  %gttmp13 = icmp sgt i32 %loaded_lhs12, 0
  %ifcond14 = icmp ne i1 %gttmp13, false
  br i1 %ifcond14, label %if.then15, label %if.end16

if.then15:                                        ; preds = %entry8
  call void (ptr, ...) @printf(ptr @3, i32 1)
  br label %if.end16

if.end16:                                         ; preds = %if.then15, %entry8
  %a17 = alloca i32, align 4
  store i32 3, ptr %a17, align 4
  %loaded_from_var18 = load i32, ptr %a17, align 4
  store i32 %loaded_from_var18, ptr %a17, align 4
  %result19 = alloca i32, align 4
  %loaded_rhs20 = load i32, ptr %a17, align 4
  store i32 %loaded_rhs20, ptr %result19, align 4
  %loaded_int21 = load i32, ptr %result19, align 4
  call void (ptr, ...) @printf(ptr @4, i32 %loaded_int21)
  %loaded_int22 = load i32, ptr %a17, align 4
  call void (ptr, ...) @printf(ptr @5, i32 %loaded_int22)
  %ret_val23 = load i32, ptr %result19, align 4
  ret i32 %ret_val23
}

declare void @printf(ptr, ...)
