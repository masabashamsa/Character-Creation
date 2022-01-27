<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=<device-width>, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <div class="one">
        <h2>Login</h2>
        <p>Please fill in your credentials to login.</p>

        <form action="./processes/login.php" method="post">
            <div class="formgroup">
                <label>Username</label>
                <input type="text" name="username">
                <span class="invalid feedback"></span>
            </div>
            <div class="two">
                <label>Password</label>
                <input type="password" name="password">
                <span class="invalid feedback"></span>
            </div>
            <div class="three">
                <input type="submit" value="Login" name="login_button">
            </div>
           
            <p>Dont have an account?<a href="index.php"> signup now</a></p>
        </form>
    </div>
</body>

</html>