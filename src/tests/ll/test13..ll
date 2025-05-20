; ModuleID = 'fib'
source_filename = "fib"
target datalayout = "e-m:o-i64:64-n32:64-S128"
target triple = "arm64-apple-darwin"

@.str = private unnamed_addr constant [21 x i8] c"Fibonacci result:\0A\00", align 1
@.print_format = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(ptr, ...)

define i32 @fib(i32 %val) {
entry:
  %is_zero = icmp eq i32 %val, 0
  br i1 %is_zero, label %return_zero, label %check_one

return_zero:
  ret i32 0

check_one:
  %is_one = icmp eq i32 %val, 1
  br i1 %is_one, label %return_one, label %recurse

return_one:
  ret i32 1

recurse:
  %val_minus_1 = sub i32 %val, 1
  %val_minus_2 = sub i32 %val, 2
  %fib1 = call i32 @fib(i32 %val_minus_1)
  %fib2 = call i32 @fib(i32 %val_minus_2)
  %sum = add i32 %fib1, %fib2
  ret i32 %sum
}

define i32 @main() {
entry:
  %n = alloca i32, align 4
  %result = alloca i32, align 4

  store i32 10, ptr %n, align 4
  %n_val = load i32, ptr %n, align 4
  %fib_result = call i32 @fib(i32 %n_val)
  store i32 %fib_result, ptr %result, align 4

  call void @printf(ptr @.str)
  %res_loaded = load i32, ptr %result, align 4
  call void (ptr, ...) @printf(ptr @.print_format, i32 %res_loaded)

  ret i32 0
}