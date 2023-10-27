--ejercicio 1
esCero :: Int -> Bool
esCero n = n == 0
{-
    Ejemplos de uso:
    *Main> esCero 0
    *Main> True
    *Main> esCero 1
    *Main> False
-}
esPositivo :: Int -> Bool
esPositivo n = n >= 0
{-
    Ejemplos de uso:
    *Main> esPositivo 0
    *Main> True
    *Main> esPositivo 1
    *Main> True
    *Main> esPositivo (-1)
    *Main> False
-}
esVocal :: Char -> Bool
esVocal l = l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u'
{-
    Ejemplos de uso:
    *Main> esVocal 'a'
    *Main> True
    *Main> esVocal 'e'
    *Main> True
    *Main> esVocal 'i'
    *Main> True
    *Main> esVocal 'o'
    *Main> True
    *Main> esVocal 'u'
    *Main> True
    *Main> esVocal 'g'
    *Main> False
-}
valorAbsoluto :: Int -> Int
valorAbsoluto n | n<0 = -1*n
                  | otherwise = n
{-
    Ejemplos de uso:
    *Main> valorAbsoluto 0
    *Main> 0
    *Main> valorAbsoluto 1
    *Main> 1
    *Main> valorAbsoluto (-1)
    *Main> 1
-}
--ejercicio 2
paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) = x && paratodo xs 
{-
    Ejemplos de uso:
    *Main> paratodo [True, True, True]
    *Main> True
    *Main> paratodo [True, False, True]
    *Main> False
-}
sumatoria :: [Int] -> Int 
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs
{-
    Ejemplos de uso:
    *Main> sumatoria [3, 7, 10]
    *Main> 20
    *Main> sumatoria [-10, 10, 1, -1, 999]
    *Main> 999
-}
productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs
{-
    Ejemplos de uso:
    *Main> productoria [3, 7, 10]
    *Main> 210
    *Main> productoria [-10, 10, 1, -1, 999]
    *Main> 99900
-}
factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)
{-
    Ejemplos de uso:
    *Main> factorial 6
    *Main> 720
    *Main> factorial 8
    *Main> 40320
    *Main> factorial 0
    *Main> 1
-}
promedio :: [Int] -> Int 
promedio xs = div (sumatoria xs) (length xs)
{-
    Ejemplos de uso:
    *Main> promedio [3, 7, 10]
    *Main> 6
    *Main> promedio [-10, 10, 1, -1, 999]
    *Main> 199
-}
--ejercicio 3
pertenece :: Int -> [Int] -> Bool
pertenece n [] = False
pertenece n (x:xs) = n == x || pertenece n xs 
{-
    Ejemplos de uso:
    *Main> pertenece 7 [3, 7, 10]
    *Main> True
    *Main> pertenece 99 [-10, 10, 1, -1, 999]
    *Main> False
-}
--ejercicio 4
paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] t = True
paratodo' (x:xs) t = (t x) && (paratodo' xs t)
{-
    Ejemplos de uso:
    *Main> pertenece 7 [3, 7, 10]
    *Main> True
    *Main> pertenece 99 [-10, 10, 1, -1, 999]
    *Main> False
-}
existe' :: [a] -> (a -> Bool) -> Bool
existe' [] t = False
existe' (x:xs) t = (t x) || existe' xs t
{-
    Ejemplos de uso:
    *Main> existe' [3, 7, -10] esPositivo
    *Main> True
    *Main> existe' [-10, 10, 1, -1, 999] esCero
    *Main> False
-}
sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] t = 0
sumatoria' (x:xs) t = (t x) + sumatoria' xs t
{-
    Ejemplos de uso:
    *Main> sumatoria' [3, 4, 2] factorial
    *Main> 32
    *Main> sumatoria' [-10, 10, 1, -1, 999] valorAbsoluto
    *Main> 1021
-}
productoria' :: [a] -> (a -> Int) -> Int
productoria' [] t = 1
productoria' (x:xs) t = (t x) * productoria' xs t
{-
    Ejemplos de uso:
    *Main> productoria' [3, 4, 2] factorial
    *Main> 288
    *Main> productoria' [-10, 10, 1, -1, 999] valorAbsoluto
    *Main> 99900
-}
--ejercicio 5
paratodo'' :: [Bool]-> Bool
paratodo'' xs = paratodo' xs (== True)
{-
    Ejemplos de uso:
    *Main> paratodo'' [True, True]
    *Main> True
    *Main> paratodo'' [True, True, True, False]
    *Main> False
-}
--ejercicio 6
todosPares :: [Int] -> Bool
todosPares xs = paratodo' xs (even)
{-
    Ejemplos de uso:
    *Main> todosPares [2, 4]
    *Main> True
    *Main> todosPares [2, 8, 9, 10]
    *Main> False
-}
esMultiplo :: Int -> Int -> Bool
esMultiplo y n | (n `mod` y) == 0 = True
               | otherwise      = False
{-
    Ejemplos de uso:
    *Main> esMultiplo 2 4
    *Main> True
    *Main> esMultiplo 2 9
    *Main> False
-}          
hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo n xs = existe' xs (esMultiplo n)
{-
    Ejemplos de uso:
    *Main> hayMultiplo 2 [3,55,6,99]
    *Main> True
    *Main> hayMultiplo 5 [3,99,2]
    *Main> False
-} 
sumaCuadrados :: Int -> Int 
sumaCuadrados n = sumatoria' [0..n] (^2)
{-
    Ejemplos de uso:
    *Main> sumaCuadrados 2
    *Main> 5
    *Main> sumaCuadrados 9
    *Main> 285
-} 
esDiv :: Int -> Int -> Bool
esDiv x n = mod x n == 0
{-
    Ejemplos de uso:
    *Main> esDiv 6 3
    *Main> True
    *Main> esDiv 9 10
    *Main> False
-} 
existeDivisor :: Int-> [Int] -> Bool
existeDivisor n xs = existe' xs (esDiv n)
{-
    Ejemplos de uso:
    *Main> existeDivisor 6 [3,12,10,2]
    *Main> True
    *Main> existeDivisor 5 [3,99,2]
    *Main> False
-} 
factorial' :: Int -> Int
factorial' n = productoria [1..n]
{-
    Ejemplos de uso:
    *Main> factorial' 6
    *Main> 720
    *Main> factorial' 10
    *Main> 3628800
-} 
esPrimo :: Int -> Bool
esPrimo n = n>0 && not (existeDivisor n [2..n-1])
{-
    Ejemplos de uso:
    *Main> esPrimo 6
    *Main> False
    *Main> esPrimo 23
    *Main> True
-} 
multiplicaPrimos :: [Int] -> Int
multiplicaPrimos xs = productoria' (filter esPrimo xs) (*1)
{-
    Ejemplos de uso:
    *Main> multiplicaPrimos [6,3,8,9,11]
    *Main> 33
    *Main> multiplicaPrimos [4,6,8]
    *Main> 1
-} 
fib :: Int -> Int
fib 0 = 1
fib 1 = 1
fib n = fib (n-1) + fib (n-2)
{-
    Ejemplos de uso:
    *Main> fib 8
    *Main> 34
    *Main> fib 2
    *Main> 2
-} 
esFib :: Int -> Bool
esFib n = existe' (map fib [0..n]) (==n)
{-
    Ejemplos de uso:
    *Main> esFib 7
    *Main> False
    *Main> esFib 34
    *Main> True
-} 
todosFib :: [Int] -> Bool
todosFib xs = paratodo' xs esFib

--ejercicio 7

--map: la funcion map toma una funcion y una lista y aplica la funcion a cada elemento de esa lista generando una nueva lista. La expresion map succ [1, -4, 6, 2, -8], donde succ n = n+1, devuelve [2,-3,7,3,-7]

--filter: la funcion filter toma una condicion y una lista y devuelve una lista formada por los elementos de la lista que cumplen con la condicion dada por el primer argumento. la expresión filter esPositivo [1, -4, 6, 2, -8] devuelve [1,6,2]

--ejercicio 8
duplicaNumeros :: [Int] -> [Int] 
duplicaNumeros [] = [] 
duplicaNumeros (x:xs) = x*2: duplicaNumeros xs
{-
    Ejemplos de uso:
    *Main> duplicaNumeros [6,3,8,9,11]
    *Main> [12,6,16,18,22]
    *Main> duplicaNumeros [12,2,3]
    *Main> [24,4,6]
-}
duplicaNumeros' :: [Int] -> [Int] 
duplicaNumeros' xs = map (*2) xs 
{-
    Ejemplos de uso:
    *Main> duplicaNumeros' [123,4,66,2]
    *Main> [246,8,132,4]
    *Main> duplicaNumeros' [0,8,4]
    *Main> [0,16,8]
-}
--ejercicio 9
filtraPrimos :: [Int] -> [Int]
filtraPrimos [] = []
filtraPrimos (x:xs) | esPrimo x = x:(filtraPrimos xs)
                    | otherwise = filtraPrimos xs
{-
    Ejemplos de uso:
    *Main> filtraPrimos [123,4,66,2]
    *Main> [2]
    *Main> filtraPrimos [0,8,4]
    *Main> []
-}
filtraPrimos' :: [Int] -> [Int]
filtraPrimos' xs = filter esPrimo xs
{-
    Ejemplos de uso:
    *Main> filtraPrimos' [27,88,99,11,2]
    *Main> [11,2]
    *Main> filtraPrimos' [37,44,11,202]
    *Main> [37,11]
-}
multiplicaPrimos'' :: [Int] -> Int
multiplicaPrimos'' xs = productoria (filtraPrimos' xs)
{-
    Ejemplos de uso:
    *Main> multiplicaPrimos'' [2,3,11,4124]
    *Main> 66
    *Main> multiplicaPrimos'' [99,2,7,9]
    *Main> 14
-}
--ejercicio 10
primIgualesA :: Eq a => a -> [a] -> [a]
primIgualesA _ [] = []
primIgualesA l (x:xs) |(l==x) = x:(primIgualesA l xs)
                      | otherwise = primIgualesA l []
{-
    Ejemplos de uso:
    *Main> primIgualesA 3 [2,3,11,4124]
    *Main> []
    *Main> primIgualesA 3 [3,3,3,4,3]
    *Main> [3,3,3]
-}
primIgualesA' :: Eq a => a -> [a] -> [a]
primIgualesA' l xs = takeWhile (== l) xs
{-
    Ejemplos de uso:
    *Main> primIgualesA' 7 [7,7,7,7,8]
    *Main> [7,7,7,7]
    *Main> primIgualesA' 3 [4,4,4,4,3]
    *Main> []
-}
--ejercicio 11

primIguales :: Eq a => [a] -> [a]
primIguales [] = []
primIguales [x] = [x] 
primIguales (x:y:xs) | (x==y) = x:(primIguales (y:xs))
                     | otherwise = [x]
{-
    Ejemplos de uso:
    *Main> primIguales [7,7,7,7,8]
    *Main> [7,7,7,7]
    *Main> primIguales [11,11,11,11,3]
    *Main> [11,11,11,11]
-}
primIguales':: Eq a => [a] -> [a]
primIguales' xs = primIgualesA (head xs) xs
{-
    Ejemplos de uso:
    *Main> primIguales' [5,5,2,3]
    *Main> [5,5]
    *Main> primIguales' [2,2,2,2,2,2,2,8,2,2,2]
    *Main> [2,2,2,2,2,2,2]
-}