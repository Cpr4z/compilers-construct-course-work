; ModuleID = 'generated'
source_filename = "generated"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-n32:64-S128-Fn32"
target triple = "arm64-apple-darwin23.4.0"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@3 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define i32 @main() {
entry:
  %retval = alloca i32, align 4
  %x = alloca i32, align 4
  store i32 5, ptr %x, align 4
  %loaded_from_var = load i32, ptr %x, align 4
  store i32 %loaded_from_var, ptr %x, align 4
  %calltmp = call i32 @goTOfunc(i32 0)
  %x1 = alloca i32, align 4
  store i32 3, ptr %x1, align 4
  %loaded_from_var2 = load i32, ptr %x1, align 4
  store i32 %loaded_from_var2, ptr %x1, align 4
  %calltmp3 = call i32 @goTOfunc(i32 4)
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret
}

define i32 @goTOfunc(i32 %y) {
entry:
  %y1 = alloca i32, align 4
  store i32 %y, ptr %y1, align 4
  %retval = alloca i32, align 4
  %loaded_lhs = load i32, ptr %y1, align 4
  %gttmp = icmp sgt i32 %loaded_lhs, 0
  %ifcond = icmp ne i1 %gttmp, false
  br i1 %ifcond, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  br label %label1

if.end:                                           ; preds = %after_goto, %entry
  call void (ptr, ...) @printf(ptr @0, i32 0)
  br label %label1

label1:                                           ; preds = %if.end9, %if.then8, %if.end, %if.then
  call void (ptr, ...) @printf(ptr @1, i32 42)
  %ret = load i32, ptr %retval, align 4
  ret i32 %ret
  call void (ptr, ...) @printf(ptr @3, i32 42)
  %ret11 = load i32, ptr %retval4, align 4
  ret i32 %ret11

after_goto:                                       ; No predecessors!
  br label %if.end

entry2:                                           ; No predecessors!
  %y3 = alloca i32, align 4
  store i32 %y, ptr %y3, align 4
  %retval4 = alloca i32, align 4
  %loaded_lhs5 = load i32, ptr %y3, align 4
  %gttmp6 = icmp sgt i32 %loaded_lhs5, 0
  %ifcond7 = icmp ne i1 %gttmp6, false
  br i1 %ifcond7, label %if.then8, label %if.end9

if.then8:                                         ; preds = %entry2
  br label %label1

if.end9:                                          ; preds = %after_goto10, %entry2
  call void (ptr, ...) @printf(ptr @2, i32 0)
  br label %label1

after_goto10:                                     ; No predecessors!
  br label %if.end9
}

declare void @printf(ptr, ...)
