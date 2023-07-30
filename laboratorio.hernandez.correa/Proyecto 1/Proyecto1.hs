--ejercicio 1
esCero :: Int -> Bool
esCero n | n == 0 = True
         | otherwise = False

esPositivo :: Int -> Bool
esPositivo n | n >= 0 = True
             | otherwise = False

esVocal :: Char -> Bool
esVocal l | l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u'  = True
          | otherwise = False

--ejercicio 2
paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) = x && paratodo xs 

sumatoria :: [Int] -> Int 
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs

factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)

promedio :: [Int] -> Int 
promedio xs = div (sumatoria xs) (length xs)

--ejercicio 3
pertenece :: Int -> [Int] -> Bool
pertenece n [] = False
pertenece n (x:xs) = n == x || pertenece n xs 

--ejercicio 4
paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] t = True
paratodo' (x:xs) t = (t x) && (paratodo' xs t)

existe' :: [a] -> (a -> Bool) -> Bool
existe' [] t = False
existe' (x:xs) t = (t x) || existe' xs t

sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] t = 0
sumatoria' (x:xs) t = (t x) + sumatoria' xs t

productoria' :: [a] -> (a -> Int) -> Int
productoria' [] t = 1
productoria' (x:xs) t = (t x) * productoria' xs t

--ejercicio 5
paratodo'' :: [Bool]-> Bool
paratodo'' xs = paratodo' xs (== True)

--ejercicio 6
todosPares :: [Int] -> Bool
todosPares xs = paratodo' xs (even)

esMultiplo :: Int -> Int -> Bool
esMultiplo y n | (n `mod` y) == 0 = True
               | otherwise      = False
                
hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo n xs = existe' xs (esMultiplo n)

sumaCuadrados :: Int -> Int 
sumaCuadrados n = sumatoria' [0..n] (^2)

factorial' :: Int -> Int
factorial' n = productoria [1..n]

pares :: Int -> Int
pares n  | n `mod` 2 == 0 = n
         | otherwise = 1

multiplicaPares :: [Int] -> Int
multiplicaPares xs = productoria' xs pares

--ejercicio 7

--map: la funcion map toma una funcion y una lista y aplica la funcion a cada elemento de esa lista generando una nueva lista. La expresion map succ [1, -4, 6, 2, -8], donde succ n = n+1, devuelve [2,-3,7,3,-7]

--filter: la funcion filter toma una condicion y una lista y devuelve una lista formada por los elementos de la lista que cumplen con la condicion dada por el primer argumento. la expresión filter esPositivo [1, -4, 6, 2, -8] devuelve [1,6,2]

--ejercicio 8
duplicaNumeros :: [Int] -> [Int] 
duplicaNumeros [] = [] 
duplicaNumeros (x:xs) = x*2: duplicaNumeros xs

duplicaNumeros' :: [Int] -> [Int] 
duplicaNumeros' xs = map (*2) xs 

--ejercicio 9
eliminaImpares :: [Int] -> [Int]
eliminaImpares [] = []
eliminaImpares (x:xs) | x `mod` 2 == 0 = x:(eliminaImpares xs)
                      | otherwise = eliminaImpares xs

eliminaImpares' :: [Int] -> [Int]
eliminaImpares' xs = filter (even) xs

multiplicaPares'' :: [Int] -> Int
multiplicaPares'' xs = productoria (eliminaImpares' xs)

--ejercicio 10
primIgualesA :: Eq a => a -> [a] -> [a]
primIgualesA l [] = []
primIgualesA l (x:xs) |(l==x) = x:(primIgualesA l xs)
                      | otherwise = []

primIgualesA' :: Eq a => a -> [a] -> [a]
primIgualesA' l xs = takeWhile (== l) xs

--ejercicio 11

primIguales :: Eq a => [a] -> [a]
primIguales [] = []
primIguales [x] = [x] 
primIguales (x:y:xs) | (x==y) = x:(primIguales (y:xs))
                     | otherwise = [x]

primIguales':: Eq a => [a] -> [a]
primIguales' xs = primIgualesA (head xs) xs 



--ejercicio 12
cuantGen :: (b -> b -> b) -> b -> [a] -> (a -> b) -> b
cuantGen op z [] _ = z
cuantGen op z (x:xs) t = t x `op` cuantGen op z xs t 

paratodo''' :: [a] -> (a -> Bool) -> Bool
paratodo''' xs t = cuantGen (&&) (True) xs t

existe''' :: [a] -> (a -> Bool) -> Bool
existe''' xs f = cuantGen (||) (False) xs f 

sumatoria''' :: [a] -> (a -> Int) -> Int
sumatoria''' xs f = cuantGen (+) 0 xs f 

productoria''' :: [a] -> (a -> Int) -> Int
productoria''' xs f = cuantGen (*) 1 xs f

{--ejercicio 13


a) f :: (a, b) -> ...
f (x , y) = ...
x :: a 
y :: b
(x, y) :: (a, b) Esta bien tipado

b) f :: [(a, b)] -> ...
f (a , b) = ... 
No esta bien tipado porque [(a,b)] es una lista y el argumento es de tipo par ordendo.
Y falta el caso base

c) f :: [(a, b)] -> ...
f (x:xs) = ...
Esta bien tipado si cada elemento x = (a,b) pero falta caso base

d) f :: [(a, b)] -> ...
f ((x, y) : ((a, b) : xs)) = ...
x :: a
y :: b 
(x , y) :: (a , b) 
(x:xs) seria x:(y:xs)
Esta bien tipado. Pero falta definir el caso con al menos un elemento.


e) f :: [(Int, a)] -> ..
	f [(0,a)] Esta bien tipado, pero falta caso base
	f ((1, x) : xs)


f ) f :: [(Int, a)] -> ...
f ((x, 1) : xs)= ...

Esta mal tipado porque para poder hacer pattern-matching con respecto a 1 necesitamos poder usar la igualdad 
y en ningun momento restringimos Eq -> a para hacer dicha comparacion.

g) f :: (Int -> Int) -> Int -> ...
f a b = ...

a :: (Int -> Int),b -> Int

h) f :: (Int -> Int) -> Int -> ...
f a 3 = ... si esta bien tipado suponiendo que (int->int) es a y sea una funcion e Int es 3


i) f :: (Int -> Int) -> Int -> ...
f 0 1 2 = ..

(Int -> Int) -> Int :: 0 1 2
(Int -> Int ) :: 0 1
Int :: 2 

No funciona porque deberia ser una funcion o solo una entrada de un numero, no dos (0 1).
 

--ejercicio 14
Si la declaracioon es f :: (a, b) -> a,
la respuesta es: f (x,y) = x

a) f :: (a, b) -> b
f (_,y) = y

b) f :: (a, b) -> c
no es posible declarar la funcìon al no conocer c 

c) f:: (a -> b) -> a -> b
f q a = q a

d)
f :: (a -> b) -> [a] -> [b]
f _ [] = []
f q (x:xs) = q x : f q xs


e) f :: (a -> b) -> (b -> c) -> a -> c
f q r a = r (q a)

-} 
