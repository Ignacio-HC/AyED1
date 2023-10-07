-- a)
data Carrera = Matematica | Fisica | Computacion | Astronomia
-- b)
titulo :: Carrera -> String
titulo Computacion = "Lic. en Ciencias de la Computacion"
titulo Matematica = "Lic. en Matematica"
titulo Fisica = "Lic. en Fisica"
titulo Astronomia = "Lic. en Astronomia"
-- c)
data NotaBasica = Re | Do | Mi | Fa | Sol | La | Si deriving (Eq, Ord, Show)    
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

data Zona = Arco | Defensa | Mediocampo | Delantera deriving Show
data TipoReves =  DosManos | UnaMano deriving Show
data Modalidad = Carretera | Pista | Monte | BMX deriving Show
data PiernaHabil = Izquierda | Derecha deriving Show
type ManoHabil = PiernaHabil

data Deportista = Ajedrecista 
                | Ciclista Modalidad
                | Velocista Altura
                | Tenista TipoReves ManoHabil Altura
                | Futbolista Zona NumCamiseta PiernaHabil Altura 
                deriving Show
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
-- e)
contar_futbolistas' :: [Deportista] -> Zona -> Int
juegaEnZona :: Zona -> Deportista -> Bool
juegaEnZona Arco (Futbolista Arco _ _ _) = True
juegaEnZona Defensa (Futbolista Defensa _ _ _) = True
juegaEnZona Mediocampo (Futbolista Mediocampo _ _ _) = True
juegaEnZona Delantera (Futbolista Delantera _ _ _) = True
juegaEnZona _ _ = False
contar_futbolistas' (x:xs) z = length (filter (juegaEnZona z) xs)

-- 5
-- a)
sonidoNatural :: NotaBasica -> Int
sonidoNatural Do = 0
sonidoNatural Re = 2
sonidoNatural Mi = 4
sonidoNatural Fa = 5
sonidoNatural Sol = 7
sonidoNatural La = 9
sonidoNatural Si = 11
-- b)
data Alteracion = Bemol | Natural | Sostenido
-- c)
data NotaMusical = Nota NotaBasica Alteracion
-- d)
sonidoCromatico :: NotaMusical -> Int 
sonidoCromatico (Nota n Sostenido) = sonidoNatural n + 1
sonidoCromatico (Nota n Bemol) = sonidoNatural n - 1
sonidoCromatico (Nota n Natural) = sonidoNatural n
-- e)
instance Eq NotaMusical where
    n1 == n2 = sonidoCromatico n1 == sonidoCromatico n2
-- f)
instance Ord NotaMusical where
    n1 <= n2 = sonidoCromatico n1 <= sonidoCromatico n2

-- 6
-- a)
primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento (x:xs) = Just x

-- 7
data Cola = VaciaC | Encolada Deportista Cola
    deriving Show
-- a)
-- 1)
atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada d c) = Just c

--2
encolar :: Deportista -> Cola -> Cola
encolar dep VaciaC = Encolada dep VaciaC
encolar dep (Encolada d c) = Encolada d (encolar dep c)

--3
busca :: Cola -> Zona -> Maybe Deportista
busca VaciaC _ = Nothing
busca (Encolada (Futbolista Defensa n p a) c) Defensa = Just (Futbolista Defensa n p a)
busca (Encolada (Futbolista Arco n p a) c) Arco = Just (Futbolista Arco n p a)
busca (Encolada (Futbolista Delantera n p a) c) Delantera = Just (Futbolista Delantera n p a)
busca (Encolada (Futbolista Mediocampo n p a) c) Mediocampo = Just (Futbolista Mediocampo n p a)
busca (Encolada _ c) z = busca c z

-- b)
-- Cola se parece a List.

-- 8
data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving Show

type Palabra = String
type Definicion = Palabra
type Diccionario = ListaAsoc Palabra Definicion

type Dni = Int
type Lugar = String
type Padron = ListaAsoc Dni Lugar

-- a)
-- se deberia instanciar de la siguiente manera:
-- type Nombre = String
-- type Telefono = Int
-- type GuiaTelefonica = ListaAsoc Nombre Telefono

-- b)
-- 1
la_long :: ListaAsoc a b -> Int
la_long Vacia = 0
la_long (Nodo _ _ la) = 1 + la_long la

-- 2
la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat Vacia l2 = l2
la_concat (Nodo a b Vacia) l2 = Nodo a b l2
la_concat (Nodo a b la) l2 = la_concat la l2

-- 3
la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar Vacia a2 b2 = Nodo a2 b2 Vacia
la_agregar (Nodo a b la) a2 b2 | a == a2 = Nodo a b2 la
                               | otherwise = Nodo a b (la_agregar la a2 b2)

-- 4
la_pares :: ListaAsoc a b -> [(a,b)]
la_pares Vacia = []
la_pares (Nodo a b la) = (a,b) : la_pares la

-- 5
la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca Vacia _ = Nothing
la_busca (Nodo a b la) a2 | a == a2 = Just b
                          | otherwise = la_busca la a2
-- 6
la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b
la_borrar _ Vacia = Vacia
la_borrar a2 (Nodo a b la) | a == a2 = la
                           | otherwise = Nodo a b (la_borrar a2 la)

-- 9*
data Arbol a = Hoja | Rama ( Arbol a ) a ( Arbol a )

-- a)
a_long :: Arbol a -> Int
a_long Hoja = 0
a_long (Rama a1 a a2) = 1 + a_long a1 + a_long a2

-- b)
a_hojas :: Arbol a -> Int
a_hojas Hoja = 1
a_hojas (Rama a1 a a2) = a_hojas a1 + a_hojas a2

-- c)
a_inc :: Num a => Arbol a -> Arbol a
a_inc Hoja = Hoja
a_inc (Rama a1 n a2) = Rama (a_inc a1) (n+1) (a_inc a2)

-- d)
a_map :: (a->b) -> Arbol a -> Arbol b
a_map _ Hoja = Hoja
a_map f (Rama a1 a a2) = Rama (a_map f a1) (f a) (a_map f a2) 