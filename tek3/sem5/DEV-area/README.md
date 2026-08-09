# Nell Backend API

This is the API documentation for the Django server `nell_backend`.

## Getting Started

To get the server running locally:

1. Clone this repository.
2. Install the required packages:
    ```bash
    pip install -r requirements.txt
    ```
3. Apply the migrations:
    ```bash
    python manage.py migrate
    ```
4. Start the development server:
    ```bash
    python manage.py runserver
    ```

## API Endpoints

### Authentication

#### Register a new user
- **URL:** `/api/auth/register/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "username": "string",
        "password": "string",
        "email": "string"
    }
    ```
- **Response:**
    ```json
    {
        "id": "integer",
        "username": "string",
        "email": "string"
    }
    ```

#### Login
- **URL:** `/api/auth/login/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "username": "string",
        "password": "string"
    }
    ```
- **Response:**
    ```json
    {
        "token": "string"
    }
    ```

#### Obtain JWT Token
- **URL:** `/api/auth/token/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "username": "string",
        "password": "string"
    }
    ```
- **Response:**
    ```json
    {
        "access": "string",
        "refresh": "string"
    }
    ```

#### Refresh JWT Token
- **URL:** `/api/auth/token/refresh/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "refresh": "string"
    }
    ```
- **Response:**
    ```json
    {
        "access": "string"
    }
    ```

#### OAuth Login
- **URL:** `/api/auth/<provider>/login/`
- **Method:** `GET`
- **Response:**
    ```json
    {
        "authorization_url": "string"
    }
    ```

#### OAuth Callback
- **URL:** `/api/auth/<provider>/callback/`
- **Method:** `GET`
- **Response:**
    ```json
    {
        "token": "string"
    }
    ```

#### User Info
- **URL:** `/api/auth/user-info/<username>/`
- **Method:** `GET`
- **Response:**
    ```json
    {
        "id": "integer",
        "username": "string",
        "email": "string"
    }
    ```

### Twitch

#### Check Twitch Live Status
- **URL:** `/api/twitchs/check-twitch-live/`
- **Method:** `GET`
- **Response:**
    ```json
    {
        "status": "string"
    }
    ```

#### Post to Bluesky
- **URL:** `/api/twitchs/post-to-bluesky/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "message": "string"
    }
    ```
- **Response:**
    ```json
    {
        "status": "string"
    }
    ```

#### Setup Bluesky User
- **URL:** `/api/twitchs/setup-bluesky-user/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "username": "string"
    }
    ```
- **Response:**
    ```json
    {
        "status": "string"
    }
    ```

#### Check and Post to Bluesky
- **URL:** `/api/twitchs/check-and-post-to-bluesky/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "message": "string"
    }
    ```
- **Response:**
    ```json
    {
        "status": "string"
    }
    ```

#### Check and Play Spotify
- **URL:** `/api/twitchs/check-and-play-spotify/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "track": "string"
    }
    ```
- **Response:**
    ```json
    {
        "status": "string"
    }
    ```

#### Twitch Live Actions
- **URL:** `/api/twitchs/twitch-live-actions/`
- **Method:** `GET`, `POST`
- **Response:**
    ```json
    {
        "id": "integer",
        "action": "string",
        "status": "string"
    }
    ```

#### Twitch Live Action Detail
- **URL:** `/api/twitchs/twitch-live-actions/<int:pk>/`
- **Method:** `GET`, `PUT`, `DELETE`
- **Response:**
    ```json
    {
        "id": "integer",
        "action": "string",
        "status": "string"
    }
    ```

#### Bluesky Post Reactions
- **URL:** `/api/twitchs/bluesky-post-reactions/`
- **Method:** `GET`, `POST`
- **Response:**
    ```json
    {
        "id": "integer",
        "reaction": "string",
        "status": "string"
    }
    ```

#### Bluesky Post Reaction Detail
- **URL:** `/api/twitchs/bluesky-post-reactions/<int:pk>/`
- **Method:** `GET`, `PUT`, `DELETE`
- **Response:**
    ```json
    {
        "id": "integer",
        "reaction": "string",
        "status": "string"
    }
    ```

### Google

#### Set Gmail Trigger
- **URL:** `/api/googlies/set-gmail-trigger/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "trigger": "string"
    }
    ```
- **Response:**
    ```json
    {
        "status": "string"
    }
    ```

#### Check for New Emails
- **URL:** `/api/googlies/check-for-new-emails/`
- **Method:** `GET`
- **Response:**
    ```json
    {
        "emails": [
            {
                "id": "string",
                "subject": "string",
                "from": "string",
                "received_at": "string"
            }
        ]
    }
    ```

#### Area Check Gmail Spotify
- **URL:** `/api/googlies/area-check-gmail-spotify/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "trigger": "string"
    }
    ```
- **Response:**
    ```json
    {
        "status": "string"
    }
    ```

#### Area Check Gmail Twitch
- **URL:** `/api/googlies/area-check-gmail-twitch/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "trigger": "string"
    }
    ```
- **Response:**
    ```json
    {
        "status": "string"
    }
    ```

#### Run Spotify Reaction
- **URL:** `/api/googlies/run-spotify-reaction/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "track": "string"
    }
    ```
- **Response:**
    ```json
    {
        "status": "string"
    }
    ```

#### Run Twitch Reaction
- **URL:** `/api/googlies/run-twitch-reaction/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "message": "string"
    }
    ```
- **Response:**
    ```json
    {
        "status": "string"
    }
    ```

#### Area Check Gmail Bluesky
- **URL:** `/api/googlies/area-check-gmail-bluesky/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "trigger": "string"
    }
    ```
- **Response:**
    ```json
    {
        "status": "string"
    }
    ```

#### Area Check Bluesky Spotify
- **URL:** `/api/googlies/area-check-bluesky-spotify/`
- **Method:** `POST`
- **Body:**
    ```json
    {
        "trigger": "string"
    }
    ```
- **Response:**
    ```json
    {
        "status": "string"
    }
    ```

### Other Endpoints

Add other endpoints as necessary, following the same structure.

## Testing

To run the tests:
```bash
python manage.py test
