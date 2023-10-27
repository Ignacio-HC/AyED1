data Categoria = Literatura | Infantiles | Autoayuda | Comics
data Editorial = Altea | Minotauro | Panini -- NO EQ, ORD
type Titulo = String
type Precio = Int
data Marca = Monoblock | Paprika -- NO EQ, ORD
type AnioAgenda = Int

data ArticulosLibreria = Libro Categoria Editorial Titulo Precio | Agenda Marca AnioAgenda Precio | Cuaderno Marca Precio -- NO EQ, ORD

-- b)
librosBaratos :: [ArticulosLibreria] -> Precio -> [ArticulosLibreria]
librosBaratos [] _ = []
librosBaratos ((Libro c e t p):xs) precio | p <= precio = (Libro c e t p) : librosBaratos xs precio
                                          | otherwise = librosBaratos xs precio

-- c)
mismaEditorial :: Editorial -> Editorial -> Bool
mismaEditorial Altea Altea = True
mismaEditorial Minotauro Minotauro = True
mismaEditorial Panini Panini = True
mismaEditorial _ _ = False

instance Eq ArticulosLibreria where
    (Libro c e t p) == (Libro c1 e1 t1 p1) = (mismaEditorial e e1 && p == p1)

data NotasDeIngles = EvolucionDelEstudiante Nombre Nivel Parcial1 Parcial2 Final NotasDeIngles | NoHayEstudiantes


type Parcial2 = Int
type Final = Int
type Nombre = String
data Nivel = Uno | Dos | Tres

type Parcial1 = Int

instance Bounded Parcial1 where
    minBound::Parcial1 = 1
    maxBound::Parcial1 = 10

