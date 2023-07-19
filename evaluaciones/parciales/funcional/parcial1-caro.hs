data Vehiculo = Moto Color Potencia | Auto Color EstiloAuto Potencia
data Color = Rojo | Azul | Blanco | Gris
data EstiloAuto = Sedan | Coupe 
type Potencia = Int 

potencia_vehiculo :: Vehiculo -> Potencia
potencia_vehiculo (Moto c p) = p
potencia_vehiculo (Auto c ea p) = p

instance Ord of Vehiculo
    where v1 <= v2 = potencia_vehiculo v1 <= potencia_vehiculo v2


--2
pintarCoupes :: [Vehiculo] -> Color -> [Vehiculo]
pintarCoupes [] newColor = []
pintarCoupes ((Moto c p):xs) newColor = pintarCoupes xs newColor
pintarCoupes ((Auto c e p):xs) newColor | e == Coupe = (Auto newColor e p) : pintarCoupes xs newColor
                                        | otherwise = pintarCoupes xs newColor