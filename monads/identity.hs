module Identity where 

newtype Identity a = Identity { runIdentity :: a }


instance Functor Identity where 
    fmap f (Identity a) = Identity (f a)


instance Applicative Identity where 
    pure a = Identity a
    (Identity f) <*> (Identity a) = Identity (f a)
    

instance Monad Identity where 
    return = Identity 
    (Identity a) >>= k = k a


inc :: (Num a) => a -> Identity a 
inc a = Identity (a + 1)


inc_by_two v = runIdentity (do
    a <- return v
    a' <- inc a
    a'' <- inc a'
    return a'')
