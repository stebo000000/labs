(defun is-odd-count (L &optional (result nil))
    (if (null L)
        result
        (is-odd-count (butlast L) (not result))))

(format t "~%is-odd-count: ~a" (is-odd-count '(1 2 3 4 5 5)))


(defun my-sum (L)
    (if (null L)
        0
        (+ (my-sum (rest L)) (first L))))

(format t "~%my-sum: ~a" (my-sum '(1 2 3 1 2)))


(defun list-deep (L)
    (if (atom L)
        0
        (max (1+ (list-deep (first L))) (list-deep (rest L)))))

(format t "~%list-deep: ~a" (list-deep '(1 2 (3) 5 (4 (2 3 5)))))


(defun find-max (L)
    (cond 
        ((null L) 0)
        ((atom L) L)
        (T (max (find-max (first L)) (find-max (rest L))))))

(format t "~%find-max: ~a" (find-max '(1 (2 4) 3 (2 (9)))))


(defun my-eval (lst &optional (stack '()) (current 0))
  (cond
    ((atom lst) (
        cond
        ((equal current "+") (push current stack))
        ((equal current "-") (push current stack))
        ((equal current "*") (push current stack))
        ((equal current "/") (push current stack))
        ((equal current "(") (push current stack))
        ((equal current ")") (push current stack))
        ((equal (first stack) "+") (+ (pop stack) (pop stack)))
        ((equal (first stack) "-") (- (pop stack) (pop stack)))
        ((equal (first stack) "*") (* (pop stack) (pop stack)))
        ((equal (first stack) "/") (/ (pop stack) (pop stack)))
    ))
    ((null current) current)
    ((list current) (my-eval (rest lst) stack (first lst)))))

(format t "~%eval: ~a" (my-eval '(2 + 3)))