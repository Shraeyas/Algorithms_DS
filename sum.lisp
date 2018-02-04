(setq x (read))
(setq y (read))
(defun diff(x y)
	(+ (* x x) (* y y))
)
(write 
(diff y x)
)