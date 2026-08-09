const {
    getAllUser,
    getAllTodo,
    getInfoByIdOrMail,
    deleteUserById,
    updateUserById
} = require('./user.query');

const auth = require('../../middleware/auth');

module.exports = function(app, bcrypt) {
    app.get('/user', auth, (req, res) => {
        getAllUser(res);
    });

    app.get('/user/todos', auth, (req, res) => {
        const user = req.user;
        getAllTodo(res, user);
    });

    app.get('/user/:data', auth, (req, res) => {
        const data = req.params.data;
        getInfoByIdOrMail(res, data);
    });

    app.delete('/user/:id', auth, (req, res) => {
        const id = req.params.id;
        deleteUserById(res, id);
    });

    app.put('/user/:id', auth, (req, res) => {
        const id = req.params.id;
        const { email, name, firstname, password } = req.body;

        if (!id || !email || !name || !firstname || !password) {
            return res.status(500).json({ "msg": "Internal server error" });
        }

        const hashedPassword = bcrypt.hashSync(password, 10);
        updateUserById(res, id, email, hashedPassword, name, firstname);
    });
};
