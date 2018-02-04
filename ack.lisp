(setq m (read))
(setq n (read))

(defun ack(m n)
	(if (= m 0)
		(return-from ack (+ n 1))
	)
	
	(if (> m 0)
		(if(= n 0)
			(return-from ack (ack (- m 1) 1))
		)
	)
	
	(if (> m 0)
		(if (> n 0)
			(return-from ack (ack(- m 1) (ack m (- n 1))))
		)
	)
)

(write (ack m n))
