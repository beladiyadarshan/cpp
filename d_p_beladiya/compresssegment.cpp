




<!doctype html>
<html>
     <head>
          <title>CHEGG</title>
     </head>
     <body>
           <script>
                var buttonss =['1','2','3','4','5'];

                function printBtn() {
                    for (var i = 0; i < buttonss.length; i++) {
                       var btn = document.createElement("button");
                       var temp = document.createTextNode(buttonss[i]);
                       btn.appendChild(temp);
                       document.body.appendChild(btn);
                    }
                }
                
                printBtn();
           </script>  
     </body>
</html>


