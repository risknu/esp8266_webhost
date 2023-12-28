void handle_css()
{
  String css = R"(
    body {
      background-color: black;
    }

    .content,
    footer {
      color: white;
      text-align: center;
    }

    .header {
      display: flex;
      justify-content: space-around;
      align-items: center;
      position: sticky;
      top: 10px;
      left: 10px;
      background-color: black;
    }

    table {
      font-family: Arial, sans-serif;
      border-collapse: collapse;
      width: 50%;
      margin: 20px auto;
    }

    th, td {
      border: 1px solid #dddddd;
      text-align: left;
      padding: 8px;
    }

    a {
      color: white;
      font-size: 20px;
    }
  )";
  Serial.println("Received request for /styles, 200");
  server.send(200, "text/css", css);
}