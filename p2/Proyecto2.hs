-- a)
data Carrera = Matematica | Fisica | Computacion | Astronomia
-- b)
titulo :: Carrera -> String
titulo Computacion = "Lic. en Ciencias de la Computacion"
titulo Matematica = "Lic. en Matematica"
titulo Fisica = "Lic. en Fisica"
titulo Astronomia = "Lic. en Astronomia"
-- c)
data NotaBasica = Re |Do | Mi | Fa | Sol | La | Si deriving (Eq, Ord, Show)    
-- d)
cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do = 'A'
cifradoAmericano Re = 'B'
cifradoAmericano Mi = 'C'
cifradoAmericano Fa = 'D'
cifradoAmericano Sol = 'E'
cifradoAmericano La = 'F'
cifradoAmericano Si = 'G'
-- 2
{-
Debemos “instanciar” las clases Eq, Ord, y Show ya que el enunciado nos pide que se pueda operar con ≥, ≤, max, y min.
A priori la unica que necesitamos al parecer es la clase Ord. Sin embargo para poder instanciar dicha clase, necesitamos tambien tener instanciada la clase Eq, (esto se debe a que la clase Ord utiliza el operador ==)???.
Luego como en Ord estan definidas las operaciones min, max, debemos instanciar la clase show, ya que el tipo de min max nos muestra que devuelven un valor del tipo que estemos comparando.
-}
-- 3
-- a)
minimoElemento :: Ord a => [a] -> a
minimoElemento [x] = x
minimoElemento (x:y:xs) | x < y = minimoElemento (x:xs)
                        | otherwise = minimoElemento (y:xs)

-- b)
minimoElemento' :: (Ord a, Bounded a) => [a] -> a
minimoElemento' [] = minBound
minimoElemento' [x] = x
minimoElemento' (x:y:xs) | x < y = minimoElemento' (x:xs)
                         | otherwise = minimoElemento' (y:xs)
-- c)
{-
 Main*> minimoElemento [Fa, La, Sol, Re, Fa]
 Re
-}

-- 4
-- a)
type Altura = Int
type NumCamiseta = Int

data Zona = Arco | Defensa | Mediocampo | Delantera
data TipoReves =  DosManos | UnaMano
data Modalidad = Carretera | Pista | Monte | BMX
data PiernaHabil = Izquierda | Derecha
data ManoHabil = PiernaHabil

data Deportista = Ajedrecista
                | Ciclista Modalidad
                | Velocista Altura
                | Tenista TipoReves ManoHabil Altura
                | Futbolista Zona NumCamiseta PiernaHabil Altura
-- b)
{-
¿Cual es el tipo del constructor Ciclista?
El tipo del constructor Ciclista es Deportista.
-} 
-- c)
contar_velocistas :: [Deportista] -> Int
contar_velocistas [] = 0
contar_velocistas ((Velocista _):xs) = 1 + contar_velocistas xs
contar_velocistas (_:xs) = contar_velocistas xs
-- d)
contar_futbolistas :: [Deportista] -> Zona -> Int
contar_futbolistas [] _ = 0
contar_futbolistas ((Futbolista Arco _ _ _):xs) Arco = 1 + contar_futbolistas xs Arco
contar_futbolistas ((Futbolista Defensa _ _ _):xs) Defensa = 1 + contar_futbolistas xs Defensa
contar_futbolistas ((Futbolista Mediocampo _ _ _):xs) Mediocampo = 1 + contar_futbolistas xs Mediocampo
contar_futbolistas ((Futbolista Delantera _ _ _):xs) Delantera = 1 + contar_futbolistas xs Delantera
contar_futbolistas (_:xs) z = contar_futbolistas xs z