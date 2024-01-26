const express = require('express');
const app = express();
const port = 3000;
const bcrypt = require('bcryptjs');
require('dotenv').config();

require('./routes/user/user')(app, bcrypt);
require('./routes/todos/todos')(app, bcrypt);
require('./routes/auth/auth')(app, bcrypt);
const notFoundHandler = require('./middleware/notFound');

app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(express.raw());

app.use(notFoundHandler);

app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`)
})