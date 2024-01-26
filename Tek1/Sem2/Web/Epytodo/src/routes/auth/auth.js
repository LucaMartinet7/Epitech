const { register, checkAccountMail, getMailAccount } = require('./../user/user.query');

module.exports = function(app, bcrypt) {
    app.post('/login', (req, res) => {
        const { email, password } = req.body;

        if (!email || !password) {
            return res.status(500).json({ "msg": "Internal server error" });
        }

        getMailAccount(res, email, password, bcrypt, (nbr) => {
            if (nbr === 84) {
                return res.status(401).json({ "msg": "Invalid credentials" });
            }
        });
    });

    app.post('/register', (req, res) => {
        const { email, name, firstname, password } = req.body;

        if (!email || !name || !firstname || !password) {
            return res.status(500).json({ "msg": "Internal server error" });
        }

        const hashedPassword = bcrypt.hashSync(password, 10);

        checkAccountMail(res, email, (nbr) => {
            if (nbr === 84) {
                return res.status(409).json({ "msg": "Account already exists" });
            } else {
                register(res, email, hashedPassword, name, firstname);
            }
        });
    });
};
