const db = require('../../config/db');
const jwt = require('jsonwebtoken');

exports.getAllUser = function(res) {
    db.query('SELECT * FROM `user`', function(err, results, fields) {
        res.status(200).json(results);
    });
};

exports.getAllTodo = function(res, id) {
    db.query('SELECT * FROM todo WHERE user_id = ?', [id], function(err, results, fields) {
        res.status(200).json(results);
    });
};

exports.register = function(res, mail, pwd, mname, fname) {
    db.execute('INSERT INTO `user` (email, password, name, firstname) VALUES (?, ?, ?, ?)', [mail, pwd, mname, fname], function(err, results, fields) {
        const token = jwt.sign({ email: mail, password: pwd }, 'SECRET');
        res.status(200).json({ token });
    });
};

exports.checkAccountMname = function(res, mname, callback) {
    db.execute('SELECT * FROM `user` WHERE name = ?', [mname], function(err, results, fields) {
        if (results.length > 0) {
            callback(84);
        } else {
            callback(0);
        }
    });
};

exports.checkAccountMail = function(res, mail, callback) {
    db.execute('SELECT * FROM `user` WHERE email = ?', [mail], function(err, results, fields) {
        if (results.length > 0) {
            callback(84);
        } else {
            callback(0);
        }
    });
};

exports.getMailAccount = function(res, mail, pwd, bcrypt, callback) {
    db.execute('SELECT password, id FROM `user` WHERE email = ?', [mail], function(err, results, fields) {
        if (results.length > 0) {
            const pwd2 = results[0].password;
            const id2 = results[0].id;
            if (bcrypt.compareSync(pwd, pwd2)) {
                const token = jwt.sign({ email: mail, id: id2 }, 'SECRET');
                res.json({ token });
                callback(0);
            } else {
                callback(84);
            }
        } else {
            callback(84);
        }
    });
};

exports.getInfoByIdOrMail = function(res, data) {
    db.execute('SELECT * FROM user WHERE email = ?', [data], function(err, results, fields) {
        if (results.length > 0) {
            res.status(200).json(results);
        } else {
            db.execute('SELECT * FROM user WHERE id = ?', [data], function(err, results, fields) {
                res.status(200).json(results);
            });
        }
    });
};

exports.deleteUserById = function(res, id) {
    db.execute('DELETE FROM `user` WHERE id = ?', [id], function(err, results, fields) {
        res.status(200).json({ "msg": `Successfully deleted record number: ${id}` });
    });
};

exports.updateUserById = function(res, id, email, pwd, mname, fname) {
    db.execute('UPDATE `user` SET email = ?, password = ?, name = ?, firstname = ? WHERE id = ?', [email, pwd, mname, fname, id], function(err, results, fields) {
        db.execute('SELECT id, email, password, created_at, firstname, name FROM user WHERE id = ?', [id], function(err, results, fields) {
            res.status(200).json(results);
        });
    });
};
