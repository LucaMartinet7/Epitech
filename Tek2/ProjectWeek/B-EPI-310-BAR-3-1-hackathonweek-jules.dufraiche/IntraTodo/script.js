document.addEventListener('DOMContentLoaded', function () {
    let currentOpenForm = null;
    let currentFeedback = null;
    const cardsTodoContainer = document.querySelectorAll('.cards-container')[0];
    const cardsDoingContainer = document.querySelectorAll('.cards-container')[1];
    const cardsDoneContainer = document.querySelectorAll('.cards-container')[2];


    const savedTodoCards = localStorage.getItem('todoCards');
    const savedDoingCards = localStorage.getItem('doingCards');
    const savedDoneCards = localStorage.getItem('doneCards');

    const initialTodoCards = savedTodoCards ? JSON.parse(savedTodoCards) : [];
    const initialDoingCards = savedDoingCards ? JSON.parse(savedDoingCards) : [];
    const initialDoneCards = savedDoneCards ? JSON.parse(savedDoneCards) : [];

    function saveCardsToLocalStorage(list) {
        if (list == "to-do") {
            const updatedCards = Array.from(cardsTodoContainer.children).map(card => {
                return {
                    cardName: card.querySelector('p').innerText,
                    linkTo: card.getAttribute('linkToVar'),
                    assignTo: card.getAttribute('assignToVar'),
                    creationDate: card.getAttribute('creationDate')
                };
            });
            localStorage.setItem('todoCards', JSON.stringify(updatedCards));
        } else if (list == "in-progress") {
            const updatedCards = Array.from(cardsDoingContainer.children).map(card => {
                return {
                    cardName: card.querySelector('p').innerText,
                    linkTo: card.getAttribute('linkToVar'),
                    assignTo: card.getAttribute('assignToVar'),
                    creationDate: card.getAttribute('creationDate')
                };
            });
            localStorage.setItem('doingCards', JSON.stringify(updatedCards));
        } else {
            const updatedCards = Array.from(cardsDoneContainer.children).map(card => {
                return {
                    cardName: card.querySelector('p').innerText,
                    linkTo: card.getAttribute('linkToVar'),
                    assignTo: card.getAttribute('assignToVar'),
                    creationDate: card.getAttribute('creationDate')
                };
            });
            localStorage.setItem('doneCards', JSON.stringify(updatedCards));
        }
    }

    initialTodoCards.forEach(cardData => {
        const card = createCard(cardData);
        cardsTodoContainer.appendChild(card);
    });
    initialDoingCards.forEach(cardData => {
        const card = createCard(cardData);
        cardsDoingContainer.appendChild(card);
    });
    initialDoneCards.forEach(cardData => {
        const card = createCard(cardData);
        cardsDoneContainer.appendChild(card);
    });

    const lists = document.querySelectorAll('.list');
    lists.forEach(list => {
        list.addEventListener('dragover', dragOver);
        list.addEventListener('dragenter', dragEnter);
        list.addEventListener('dragleave', dragLeave);
        list.addEventListener('drop', dragDrop);
        const addCardBtn = list.querySelector('.add-card-btn');
        if (addCardBtn) {
            addCardBtn.addEventListener('click', () => addCard(list));
        }
    });

    function createCard(cardData) {
        const card = document.createElement('div');
        card.classList.add('card');
        card.draggable = true;
        card.innerHTML = `
            <p>${cardData.cardName}</p>
            <i class="fa-solid fa-bars-staggered card-icon"></i>
        `;
        card.setAttribute('linkToVar', cardData.linkTo);
        card.setAttribute('assignToVar', cardData.assignTo);
        card.setAttribute('creationDate', cardData.creationDate);
        card.addEventListener('click', openEditForm);
        card.addEventListener('dragstart', dragStart);
        card.addEventListener('dragend', dragEnd);
        return card;
    }

    function openEditForm() {
        const card = this;

        if (currentOpenForm && currentOpenForm.card === card) {
            closeCurrentForm();
            return;
        }

        closeCurrentForm();

        const assignTo = card.getAttribute('assignToVar');
        const linkTo = card.getAttribute('linkToVar');
        const modal = document.createElement('div');
        modal.classList.add('modal');

        const modalContent = document.createElement('div');
        modalContent.classList.add('modal-content');

        const form = document.createElement('form');
        form.innerHTML = `
            <head> <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css"> </head>

            <label for="cardNameTxt" class="cardNameTxt" >Card Name: <i class="fa-solid fa-pencil"></i> </label>
            <input type="text" class="cardName" id="cardName" value="${card.querySelector('p').innerText}"</input>

            <a href="${linkTo}" for"projectLinkTxt" class="projectLinkTxt">Project Link: <i class="fa-solid fa-pencil"></i> </a>
            <input type="text" class="projectLink" id="projectLink" value="${linkTo}"></input>

            <label for="assignTxt" class="assignTxt" >Assign to: <i class="fa-solid fa-pencil"></i> </label>
            <input type="text" class="assignTo" id="assignTo" value="${assignTo}"></input>

            <label class='statustxt' for="status">Status:</label>
            <label class='status'>${card.closest('.list').querySelector('h2').innerText}</label>

            <label class="dateTxt" for="dateTxt">Date Created:</label>
            <label class="dateCreated">${card.getAttribute('creationDate')}</label>

            <button type="button" class="saveBtn" id="saveBtn"> <i class="fa-solid fa-floppy-disk"></i></button>
            <button type="button" class="cancelBtn" id="cancelBtn"> <i class="fa-solid fa-xmark"></i></button>
            <button type="button" id="deleteBtn" class="deleteBtn"> <i class="fa-solid fa-trash"></i> </button>
        `;

        modalContent.appendChild(form);
        modal.appendChild(modalContent);
        document.body.appendChild(modal);

        const saveBtn = form.querySelector('#saveBtn');
        const cancelBtn = form.querySelector('#cancelBtn');
        const deleteBtn = form.querySelector('#deleteBtn');

        saveBtn.addEventListener('click', saveChanges);
        cancelBtn.addEventListener('click', closeModal);
        deleteBtn.addEventListener('click', askToDeleteCard);

        form.addEventListener('submit', function (e) {
            e.preventDefault();
            saveChanges();
        });

        form.addEventListener('keydown', function (e) {
            if (e.key === 'Enter') {
                e.preventDefault();
                saveChanges();
            }
        });

        document.addEventListener('keydown', function (e) {
            if (e.key === 'Delete' && currentOpenForm === card) {
                askToDeleteCard();
            }
        });

        currentOpenForm = {modal, card};
        function saveChanges() {
            const newCardName = form.querySelector('#cardName').value;
            const newAssignTo = form.querySelector('#assignTo').value;
            const newLinkTo = form.querySelector('#projectLink').value;

            card.querySelector('p').innerText = newCardName;
            card.setAttribute('assignToVar', newAssignTo);
            card.setAttribute('linkToVar', newLinkTo);

            const listName = card.closest('.list').querySelector('h2').innerText.toLowerCase().replace(/\s/g, '-');
            saveCardsToLocalStorage(listName);
            closeModal();
        }

        function askToDeleteCard() {
            const confirmation = confirm('Are you sure you want to delete this card?');
            if (confirmation) {
                const listName = card.closest('.list').querySelector('h2').innerText.toLowerCase().replace(/\s/g, '-');
                card.remove();
                saveCardsToLocalStorage(listName)
                closeModal();
            }
        }

        function closeModal() {
            if (document.body.contains(modal)) {
                document.body.removeChild(modal);
            }
            document.removeEventListener('keydown', askToDeleteCard);
            currentOpenForm = null;
        }

        function closeCurrentForm() {
            if (currentOpenForm && document.body.contains(currentOpenForm.modal)) {
                document.body.removeChild(currentOpenForm.modal);
                document.removeEventListener('keydown', askToDeleteCard);
                currentOpenForm = null;
            }
        }
    }

    function dragStart() {
        this.classList.add('dragging');
    }

    function dragEnd() {
        this.classList.remove('dragging');
    }

    function dragOver(e) {
        e.preventDefault();
    }

    function dragEnter(e) {
        e.preventDefault();
        this.classList.add('hovered');
    }

    function dragLeave() {
        this.classList.remove('hovered');
    }

    function dragDrop() {
        const draggedCard = document.querySelector('.dragging');
        const originalList = draggedCard.closest('.list');
        const newList = this;
        if (originalList !== newList) {
            originalList.querySelector('.cards-container').removeChild(draggedCard);
            const originalListName = originalList.querySelector('h2').innerText.toLowerCase().replace(/\s/g, '-');
            saveCardsToLocalStorage(originalListName);
        }
        newList.querySelector('.cards-container').appendChild(draggedCard);
        newList.classList.remove('hovered');
        const newListName = newList.querySelector('h2').innerText.toLowerCase().replace(/\s/g, '-');
        saveCardsToLocalStorage(newListName);
    }

    function addCard(list) {
        const newCard = createCard({
                                    cardName: 'Card Name',
                                    linkTo: '#',
                                    assignTo: 'Not assigned',
                                    creationDate: new Date().toLocaleDateString()
                                });
        list.querySelector('.cards-container').appendChild(newCard);

        newCard.addEventListener('click', openEditForm);
        newCard.addEventListener('dragstart', dragStart);
        newCard.addEventListener('dragend', dragEnd);

        const listName = newCard.closest('.list').querySelector('h2').innerText.toLowerCase().replace(/\s/g, '-');
        saveCardsToLocalStorage(listName);
    }

    const pushButton = document.createElement('button');
    pushButton.classList.add('push-button');
    pushButton.innerHTML = `
        <head> <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css"> </head>
        <i class="fa-solid fa-paper-plane"></i>
    `;
    document.body.appendChild(pushButton);

    pushButton.addEventListener('click', function () {
        if (!currentFeedback) {
            const modalBackground = document.createElement('div');
            modalBackground.classList.add('modal-background');
            document.body.appendChild(modalBackground);

            const modal = document.createElement('div');
            modal.classList.add('feedback-modal');
            modal.innerHTML = `
                <span class="cancelBtn">&times;</span>
                <p style="text-align: center;">Feedback at IntraTodo@contact.com</p>
            `;

            modalBackground.appendChild(modal);
            currentFeedback = modal;

            const cancelBtn = modal.querySelector('.cancelBtn');
            cancelBtn.addEventListener('click', function () {
                document.body.removeChild(modalBackground);
                currentFeedback = null;
            });
        }
    });
});
