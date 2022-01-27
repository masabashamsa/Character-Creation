<?php
require "connection.php";

if($_SERVER["REQUEST_METHOD"]=="POST"){
    if(isset($_POST['login_button'])){
        $username = $_POST['username'];
        $password = $_POST['password'];
    
        if(empty($username)|| empty($password)){
            header("Location:.\../index.php");
            exit();
        }else{
            if(empty($username_err) && empty($password_err)){
                $sql = "SELECT id,username,password FROM login info WHERE username = ?";
            if($stmt=mysqli_prepare($connection,$sql)){
                mysqli_stmt_bind_param($stmt,"s",$param_username);
                $param_username= $username;
                if(mysqli_stmt_execute($stmt)){

                    mysqli_stmt_store_result($stmt);

                    if(mysqli_stmt_num_rows($stmt)== 1){
                        mysqli_stmt_bind_result($stmt,$id,$username,$password1);
                        if(mysqli_stmt_fetch($stmt)){
                            if(password_verify($password,$password1)){
                                session_start();

                                $_SESSION["loggedin"]= true;
                                $_SESSION["id"]= $id;
                                $_SESSION["username"]=$username;

                                header("location:teacherPage.php");
                            }
                            else{
                            $login_err="Invalid username or password";
                            }
                        }
                    } else{
                        $login_err="Invalid username or password";
                    }
                }else{
                    echo "Oops! Something went wrong. Please try again later";
                }
                mysqli_stmt_close($stmt);
            }

            }
        }
    }
    mysqli_close($connection);
}
?>