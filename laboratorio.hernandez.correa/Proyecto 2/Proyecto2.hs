--ejercicio 1
data Carrera = Matematica | Fisica | Computacion | Astronomia deriving (Eq,Ord,Bounded,Show)

titulo :: Carrera -> String
titulo Matematica = "Licenciatura en Matemática"
titulo Fisica = "Licenciatura en Física"
titulo Computacion = "Licenciatura en Computación"
titulo Astronomia = "Licenciatura en Astronomía"

--lo comento porque en el ejercicio 2 agregue los deriving
--data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si

cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do = 'C'
cifradoAmericano Re = 'D'
cifradoAmericano Mi = 'E'
cifradoAmericano Fa = 'F'
cifradoAmericano Sol = 'G'
cifradoAmericano La = 'A'
cifradoAmericano Si = 'B'

--ejercicio 2 
data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si deriving (Eq,Ord,Bounded,Show)

--ejercicio 3

minimoElemento :: Ord a => [a] -> a
minimoElemento [x] = x
minimoElemento (x:xs) = x `min` minimoElemento xs

minimoElemento' :: (Bounded a, Ord a) => [a] -> a 
minimoElemento' [] = maxBound
minimoElemento' (x:xs) = x `min` minimoElemento xs

notaGrave :: [NotaBasica] -> NotaBasica
notaGrave [x] = x
notaGrave (x:xs) = x `min` minimoElemento xs 


--ejercicio 4
type Ingreso = Int
data Cargo = Titular | Asociado | Adjunto | Asistente | Auxiliar deriving (Show)
data Area = Administrativa | Ensenanza | Economica | Postgrado deriving (Show)
data Persona = Estudiante Carrera Ingreso  | Docente Cargo | NoDocente Area | Decane deriving (Show)
-- el tipo del contructor Docente es Persona
cuantos_doc :: [Persona] -> Cargo -> Int
cuantos_doc [] _ = 0
cuantos_doc (Docente Titular:xs) Titular = 1 + cuantos_doc xs Titular
cuantos_doc (Docente Asociado:xs) Asociado = 1 + cuantos_doc xs Asociado
cuantos_doc (Docente Adjunto:xs) Adjunto = 1 + cuantos_doc xs Adjunto
cuantos_doc (Docente Asistente:xs) Asistente = 1 + cuantos_doc xs Asistente
cuantos_doc (Docente Auxiliar:xs) Auxiliar = 1 + cuantos_doc xs Auxiliar
cuantos_doc ( _ :xs) c = cuantos_doc xs c

mismoCargo :: Cargo -> Persona -> Bool 
mismoCargo Titular (Docente Titular) = True
mismoCargo Asociado (Docente Asociado) = True
mismoCargo Adjunto (Docente Adjunto) = True
mismoCargo Asistente (Docente Asistente) = True
mismoCargo Auxiliar (Docente Auxiliar) = True
mismoCargo c _ = False

cuantos_doc' :: [Persona] -> Cargo -> Int
cuantos_doc' xs c = length (filter (mismoCargo c) xs)

--ejercicio 5

data Alteracion = Bemol | Sostenido | Natural
data NotaMusical = Nota NotaBasica Alteracion

sonido :: NotaBasica -> Int
sonido Do = 1
sonido Re = 3
sonido Mi = 5
sonido Fa = 6
sonido Sol = 8
sonido La = 10
sonido Si = 12

sonidoCromatico :: NotaMusical -> Int
sonidoCromatico (Nota d Sostenido) = sonido d + 1
sonidoCromatico (Nota d Bemol) = sonido d - 1
sonidoCromatico (Nota d Natural) = sonido d

instance Eq NotaMusical where
    nm1 == nm2 = sonidoCromatico nm1 == sonidoCromatico nm2

instance Ord NotaMusical where
    ws1 <= ws2 = sonidoCromatico ws1 <= sonidoCromatico ws2

--ejercicio 6 

primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing 
primerElemento (x:xs) = Just x

--ejercicio 7

data Cola = VaciaC | Encolada Persona Cola deriving (Show)

atender :: Cola -> Maybe Cola
atender VaciaC = Nothing 
atender (Encolada p c) = Just (c)

encolar :: Persona -> Cola -> Cola
encolar p VaciaC = Encolada p VaciaC
encolar p c = Encolada p c

busca :: Cola -> Cargo -> Maybe Persona
busca VaciaC _ = Nothing 
busca (Encolada p c) carg | mismoCargo carg p = Just (p)
                          |otherwise = busca c carg

--cola se parece a un tipo lista :"D

--ejercicio 8
data ListaAsoc a b = Vacia | Nodo a b ( ListaAsoc a b ) deriving (Eq)
type Diccionario = ListaAsoc String String
type Padron = ListaAsoc Int String
--ejericio 8.a

--como se debe instanciar el tipo ListaAsoc para representar la info almacenada en una guia telefonica?
--se debe instanciar del tipo ListaAsoc NombreyApellido Tel
type NombreyApellido = String
type Tel = Int
type GuiaTel = ListaAsoc NombreyApellido Tel

long :: ListaAsoc a b -> Int
long Vacia = 0
long (Nodo a b (l)) = 1 + (long l)

la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat Vacia l = l
la_concat (Nodo a b (l)) f = la_concat l (Nodo a b (f)) 


la_agregar :: ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar l a b = (Nodo a b (l))

la_pares :: ListaAsoc a b -> [(a, b)]
la_pares Vacia = []
la_pares (Nodo a b (l)) = (a, b) : (la_pares l) 

la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca Vacia _ = Nothing 
la_busca (Nodo a b (l)) mia | a == mia = Just (b)
                            | otherwise = la_busca l mia

la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b
la_borrar _ Vacia = Vacia
la_borrar m (Nodo a b (l))| m == a = l
                          | otherwise = Nodo a b (la_borrar m l)

--ejercicio 9*
data Arbol a = Hoja | Rama ( Arbol a ) a ( Arbol a )

a_long :: Arbol a -> Int
a_long Hoja = 0
a_long (Rama l a r) = 1 + a_long l + a_long r 

a_hojas :: Arbol a -> Int
a_hojas Hoja = 1
a_hojas (Rama l a r) = a_hojas l + a_hojas r

a_inc :: Num a => Arbol a -> Arbol a
a_inc Hoja = Hoja
a_inc (Rama l a r) = (Rama (a_inc l) (a+1) (a_inc r))

a_map :: (a -> b) -> Arbol a -> Arbol b
a_map _ Hoja = Hoja
a_map f (Rama l a r) = (Rama (a_map f l) (f a) (a_map f r))


