module Reader where 


newtype Reader r a = Reader { runReader :: r -> a }


instance Functor (Reader s) where 
    fmap f m = Reader $ \e -> f $ runReader m e


instance Applicative (Reader s) where 
    pure a = Reader $ \e -> a
    f <*> m = Reader $ \e -> runReader f e $ runReader m e


instance Monad (Reader s) where 
    return = pure
    m >>= k = Reader $ \e -> 
        let v = runReader m e 
        in runReader (k v) e 


ask :: Reader a a
ask = Reader $ \e -> e


asks :: (e -> e') -> Reader e e'
asks f = Reader $ \e -> f e


local :: (e -> e') -> Reader e' a -> Reader e a
local f m = Reader $ \e -> runReader m (f e)
