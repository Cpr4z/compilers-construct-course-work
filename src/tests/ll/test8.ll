; ModuleID = 'generated'
source_filename = "generated"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-n32:64-S128-Fn32"
target triple = "arm64-apple-darwin23.4.0"

@0 = private unnamed_addr constant [10 x i8] c"a + b > 0\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@2 = private unnamed_addr constant [11 x i8] c"a + b <= 0\00", align 1
@3 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@4 = private unnamed_addr constant [10 x i8] c"a + b > 0\00", align 1
@5 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@6 = private unnamed_addr constant [11 x i8] c"a + b <= 0\00", align 1
@7 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

define i32 @main() {
entry:
  %retval = alloca i32, align 4
  %calltmp = call i32 @someFunc(i32 1982, i32 3)
  %calltmp1 = call i32 @someFunc(i32 0, i32 0)
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret
}

define i32 @someFunc(i32 %a, i32 %b) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %retval = alloca i32, align 4
  %loaded_lhs = load i32, ptr %a1, align 4
  %loaded_rhs = load i32, ptr %b2, align 4
  %addtmp = add i32 %loaded_lhs, %loaded_rhs
  %gttmp = icmp sgt i32 %addtmp, 0
  %ifcond = icmp ne i1 %gttmp, false
  br i1 %ifcond, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  call void (ptr, ...) @printf(ptr @1, ptr @0)
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret

if.else:                                          ; preds = %entry
  call void (ptr, ...) @printf(ptr @3, ptr @2)
  br label %if.end

entry3:                                           ; No predecessors!
  %a4 = alloca i32, align 4
  store i32 %a, ptr %a4, align 4
  %b5 = alloca i32, align 4
  store i32 %b, ptr %b5, align 4
  %retval6 = alloca i32, align 4
  %loaded_lhs7 = load i32, ptr %a4, align 4
  %loaded_rhs8 = load i32, ptr %b5, align 4
  %addtmp9 = add i32 %loaded_lhs7, %loaded_rhs8
  %gttmp10 = icmp sgt i32 %addtmp9, 0
  %ifcond11 = icmp ne i1 %gttmp10, false
  br i1 %ifcond11, label %if.then12, label %if.else14

if.then12:                                        ; preds = %entry3
  call void (ptr, ...) @printf(ptr @5, ptr @4)
  br label %if.end13

if.end13:                                         ; preds = %if.else14, %if.then12
  %ret15 = load i32, ptr %retval6, align 4
  ret i32 %ret15

if.else14:                                        ; preds = %entry3
  call void (ptr, ...) @printf(ptr @7, ptr @6)
  br label %if.end13
}

declare void @printf(ptr, ...)
