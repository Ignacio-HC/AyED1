

maxiga :: a -> [a] -> Int
maxiga e [] = 0
maxiga e (x:xs) = (0 `max` ((mmaxiga x xs) +1)) `max` (maxiga e xs)

mmaxiga :: a -> [a] -> Int
mmaxiga k [] = 0 
mmaxiga k (x:xs) = 0 `max` ((mmaxiga k xs)+1)


