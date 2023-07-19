-- Ejercicio 1
--a
data Color = Rojo | Azul | Blanco | Gris deriving Show
type Potencia = Int
data EstiloAuto = Coupe | Sedan deriving (Eq, Show)
data Vehiculo = Moto Color Potencia | Auto Color EstiloAuto Potencia deriving Show
--b
potencia_vehiculo :: Vehiculo -> Potencia
potencia_vehiculo (Auto c e p) = p
potencia_vehiculo (Moto c p) = p
--c
instance Ord Vehiculo  
    where
        v1 <= v2 = potencia_vehiculo v1 <= potencia_vehiculo v2
instance Eq Vehiculo
    where
        v1 == v2 = potencia_vehiculo v1 == potencia_vehiculo v2
-- Ejercicio 2
-- instance Show Vehiculo where
--   show (Moto c p) = "Moto " ++ show c ++ " " ++ show p
--   show (Auto c e p) = "Auto " ++ show c ++ " " ++ show e ++ " " ++ show p
--a
pintarCoupes :: [Vehiculo] -> Color -> [Vehiculo]
pintarCoupes [] newColor = []
pintarCoupes ((Moto c p):xs) newColor = pintarCoupes xs newColor
pintarCoupes ((Auto c e p):xs) newColor | e == Coupe = (Auto newColor e p) : pintarCoupes xs newColor
                                        | otherwise = pintarCoupes xs newColor
-- b
-- lista: Auto Rojo Coupe 300 : Moto Blanco 125 : Moto Azul 250 : Moto Gris 200 : Auto Gris Coupe 400 : [] 
--c
-- resultado de pintarCoupes [Auto Rojo Coupe 300,Moto Blanco 125,Moto Azul 250,Moto Gris 200,Auto Gris Coupe 400] Azul
-- [Auto Azul Coupe 300,Auto Azul Coupe 400]

-- Ejercicio 3
data ListaAsoc a b = Vacia | Nodo a b ( ListaAsoc a b ) deriving (Eq)

la_es_cota_inf :: Ord a => ListaAsoc a b -> a -> Bool
la_es_cota_inf Vacia _ = True
la_es_cota_inf (Nodo a _ la) x
    | x <= a = la_es_cota_inf la x
    | otherwise = False