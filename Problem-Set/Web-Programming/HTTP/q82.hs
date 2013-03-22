import Network.Browser
import Network.HTTP
import Network.URI
 
httpreq = do 
      rsp <- Network.Browser.browse $ do
                 setAllowRedirects True
		 setOutHandler $ const (return ())
                 request $ getRequest "http://www.facebook.com/"
 
      putStrLn $ rspBody $ snd rsp
 