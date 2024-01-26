const db = require('../../config/db');

exports.getAllTodo = function (res) {
    db.query('SELECT * FROM `todo`', function (err, results, fields) {
        res.status(200).json(results);
    });
};

exports.getTodoById = function (res, id) {
    db.execute('SELECT * FROM `todo` WHERE id = ?', [id], function (err, results, fields) {
        res.status(200).json(results);
    });
};

exports.createTodo = function (res, title, description, dueTime, id, status) {
    db.execute(
        'INSERT INTO `todo` (title, description, due_time, status, user_id) VALUES (?, ?, ?, ?, ?)',
        [title, description, dueTime, status, id],
        function (err, results, fields) {
            const idTask = results["insertId"];
            db.execute('SELECT * FROM `todo` WHERE id = ?', [idTask], function (err, results, fields) {
                res.status(200).json(results);
            });
        }
    );
};

exports.deleteTaskById = function (res, id) {
    db.execute('DELETE FROM `todo` WHERE id = ?', [id], function (err, results, fields) {
        res.status(200).json({ "msg": `Successfully deleted record number: ${id}` });
    });
};

exports.updateTaskById = function (res, id, title, desc, dueTime, userId, status) {
    db.execute(
        'UPDATE `todo` SET title = ?, description = ?, due_time = ?, user_id = ?, status = ? WHERE id = ?',
        [title, desc, dueTime, userId, status, id],
        function (err, results, fields) {
            db.execute('SELECT id, title, description, created_at, due_time, user_id, status FROM todo WHERE id = ?', [id], function (err, results, fields) {
                res.status(200).json(results);
            });
        }
    );
};
