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


get :: Reader a a
get = Reader $ \e -> e


add_env :: Int -> Reader Int Int
add_env v = Reader $ \e -> v + e


mult_env :: Int -> Reader Int Int 
mult_env v = Reader $ \e -> v * e


-- return n * (n + 1)
foo = runReader (do 
    v <- get
    v' <- mult_env v
    v'' <- add_env v'
    return v')

    
