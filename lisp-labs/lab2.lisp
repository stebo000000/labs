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



(defun apply-op (op left right)
  (cond ((eq op '+) (+ left right))
        ((eq op '-) (- left right))
        ((eq op '*) (* left right))
        ((eq op '/) (/ left right))
        (t )))


(defun parse-expr (tokens)
  (let ((result (parse-term tokens)))
    (parse-expr-rest (car result) (cdr result))))

(defun parse-expr-rest (left tokens)
  (cond
    ((and (consp tokens)
          (member (car tokens) '(+ -)))
     (let* ((op (car tokens))
            (rest (cdr tokens))
            (right-result (parse-term rest))
            (right (car right-result))
            (remaining (cdr right-result)))
       (parse-expr-rest (apply-op op left right) remaining)))
    (t (cons left tokens))))

(defun parse-term (tokens)
  (let ((result (parse-factor tokens)))
    (parse-term-rest (car result) (cdr result))))

(defun parse-term-rest (left tokens)
  (cond
    ((and (consp tokens)
          (member (car tokens) '(* /)))
     (let* ((op (car tokens))
            (rest (cdr tokens))
            (right-result (parse-factor rest))
            (right (car right-result))
            (remaining (cdr right-result)))
       (parse-term-rest (apply-op op left right) remaining)))
    (t (cons left tokens))))

(defun parse-factor (tokens
  (cond
    ((and (consp tokens) (eq (car tokens) '-))
     (let* ((inner (parse-factor (cdr tokens)))
            (val (car inner))
            (rem (cdr inner)))
       (cons (- val) rem)))
    ((and (consp tokens) (numberp (car tokens)))
     (cons (car tokens) (cdr tokens)))
    ((and (consp tokens) (listp (car tokens)))
     (let* ((inner-result (parse-expr (car tokens)))
            (val (car inner-result)))
       (cons val (cdr tokens))))
    (t )))


(defun eval-expr (expr)
  (let ((result (parse-expr expr)))
    (car result))))

(format t "~%eval: ~a" (eval-expr '((2 + 3) * 2)))