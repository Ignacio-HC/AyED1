-- ejercicio 1
--a
esCero :: Int -> Bool
esCero n = n == 0
--b
esPositivo :: Int -> Bool
esPositivo n = n > 0
--c
esVocal :: Char -> Bool
esVocal a | a == 'a' = True
          | a == 'e' = True
          | a == 'i' = True
          | a == 'o' = True
          | a == 'u' = True
          | otherwise = False

-- ejercicio 2
--a
paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) = x && paratodo xs
--b 
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs
--c 
productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs
--d
factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial(n-1)
--e 
promedio :: [Int] -> Int
promedio xs = sumatoria(xs) `div` length xs 

-- ejercicio 3
pertenece :: Int -> [Int] -> Bool
pertenece n [] = False
pertenece n (x:xs) = n == x || pertenece n xs

-- ejercicio 4

-- c) sumatoria’ :: [a] -> (a -> Int) -> Int, dada una lista xs de tipo [a] y una
-- funci ́on t :: a -> Int (toma elementos de tipo a y devuelve enteros), calcula la
-- suma de los valores que resultan de la aplicaci ́on de t a los elementos de xs.
-- d) productoria’ :: [a] -> (a -> Int) -> Int, dada una lista de xs de tipo [a]
-- y una funci ́on t :: a -> Int, calcula el producto de los valores que resultan de la
-- aplicaci ́on de t a los elementos de xs.

-- a
paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] f = True
paratodo' (x:xs) f = f x && paratodo' xs f

-- b) existe’ :: [a] -> (a -> Bool) -> Bool, dada una lista xs de tipo [a] y un
-- predicado t :: a -> Bool, determina si alg ́un elemento de xs satisface el predicado
-- t.