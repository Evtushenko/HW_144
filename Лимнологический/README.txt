works only for this types of queries
"func=entrace;email=email;password=password;"
"func=regitration;email=email;password=password;"

answers form server:
wrong query = in case of other type
func=registration;result=1; = success registration
func=entrace;result=1; = user found in DB
func=entrace;result=0; = user not found in DB

- change file path !! into UserBase class
