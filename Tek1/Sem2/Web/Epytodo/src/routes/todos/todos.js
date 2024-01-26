const {
    createTodo,
    getAllTodo,
    getTodoById,
    deleteTaskById,
    updateTaskById
} = require('./todos.query');

const auth = require('../../middleware/auth');
const verifyId = require('../../middleware/notFound');

module.exports = function(app, bcrypt) {
    app.get('/todo', auth, (req, res) => {
        getAllTodo(res);
    });

    app.get('/todo/:id', auth, verifyId, (req, res) => {
        const id = req.params.id;
        getTodoById(res, id);
    });

    app.post('/todo', auth, (req, res) => {
        const { title, description, due_time, user_id, status } = req.body;

        if (!title || !description || !due_time || !user_id || !status) {
            return res.status(500).json({ "msg": "Internal server error" });
        }

        createTodo(res, title, description, due_time, user_id, status);
    });

    app.delete('/todo/:id', auth, (req, res) => {
        const id = req.params.id;
        deleteTaskById(res, id);
    });

    app.put('/todo/:id', auth, (req, res) => {
        const id = req.params.id;
        const { title, description, due_time, user_id, status } = req.body;

        if (!id || !title || !description || !due_time || !user_id || !status) {
            return res.status(500).json({ "msg": "Internal server error" });
        }

        updateTaskById(res, id, title, description, due_time, user_id, status);
    });
};
