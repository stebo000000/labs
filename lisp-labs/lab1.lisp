(defun sq-sum (n m)
    (if (< n m)
        (+ (sq-sum (1+ n) m) (* n n))
        (* n n))
)

(format t "~%sq sum: ~a" (sq-sum 1 4))

(defun nod (x y)
    (if (= 0 (mod x y))
        y
        (nod y (mod x y)))
)

(format t "~%nod: ~a" (nod 4 6))

(defun nok (x y) ; хз норм ли (не рекурсия)
    (/ (* x y) (nod x y)))

(format t "~%nok: ~a" (nok 4 6))

(defun my-sqrt (x &optional (i 1))
    (if (< (* i i) x)
        (my-sqrt x (+ i 1))
        i
    ))

(format t "~%sqrt: ~a" (my-sqrt 16))


(defun fib (n &optional (a 1) (b 2))
    (if (= n 1)
        a
        (fib (- n 1) b (+ a b))
    )

)

(format t "~%fib: ~a" (fib 4))