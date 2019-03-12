(print "what your name")


(defvar *name* (read))

(+ 5 4)

(+ 5 ( - 6 2))


(defvar *age* 18)
(defvar *num-3* 1)

(unless ( = *age* 1)
  (setf *num-3* 18)
  (format t "Go to College ~d ~%" *num-3*)
  )



