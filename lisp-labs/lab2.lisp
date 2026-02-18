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
    (if (atom L)
        (if (null L)
            0
            L)
        (max (find-max (first L)) (find-max (rest L)))))

(format t "~%find-max: ~a" (find-max '(1 (2 4) 3 (2 (9)))))


(defun f2 (x)
    (not x))

(format t "~%f2: ~a" (f2 nil))