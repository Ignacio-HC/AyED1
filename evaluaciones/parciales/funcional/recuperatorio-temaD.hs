data Registro = Soprano | Contralto | Tenor | Baritono | Bajo deriving Show
data TipoCanto = Solista | Coral deriving Show
data Instrumento = Violin | Clarinete | Trompeta | Timbales deriving Show
type Trayecto = Int 

data ArtistaMusical = Cantante Registro TipoCanto Trayecto | Instrumentista Instrumento Trayecto deriving (Show)

--b)
trayectoria_musical :: ArtistaMusical -> Trayecto
trayectoria_musical (Cantante r tc tr) = tr
trayectoria_musical (Instrumentista i tr) = tr

--c)
instance Ord ArtistaMusical where
    a1 <= a2 = (trayectoria_musical a1) <= (trayectoria_musical a2)

instance Eq ArtistaMusical where
    a1 == a2 = (trayectoria_musical a1) == (trayectoria_musical a2)

-- 2
-- a)
buscarSolistas :: [ArtistaMusical] -> Registro -> [ArtistaMusical]
buscarSolistas [] _ = []
buscarSolistas ((Cantante Soprano Solista tr):xs) Soprano = (Cantante Soprano Solista tr) : buscarSolistas xs Soprano 
buscarSolistas ((Cantante Contralto Solista tr):xs) Contralto = (Cantante Contralto Solista tr) : buscarSolistas xs Contralto 
buscarSolistas ((Cantante Tenor Solista tr):xs) Tenor = (Cantante Tenor Solista tr) : buscarSolistas xs Tenor 
buscarSolistas ((Cantante Baritono Solista tr):xs) Baritono = (Cantante Baritono Solista tr) : buscarSolistas xs Baritono 
buscarSolistas ((Cantante Bajo Solista tr):xs) Bajo = (Cantante Bajo Solista tr) : buscarSolistas xs Bajo
buscarSolistas (_:xs) r = buscarSolistas xs r
-- b)
-- [Cantante Tenor Solista 3, Instrumentista Violin 4, Cantante Contralto Coral 2]
-- c)
-- [Cantante Tenor Solista 3]

-- 3
data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving Show
la_algun_multiplo :: (Integral b) => ListaAsoc a b -> b -> Bool
la_algun_multiplo Vacia _ = False
la_algun_multiplo (Nodo a b la) m | mod b m == 0 = True
                                  | otherwise = la_algun_multiplo la m
