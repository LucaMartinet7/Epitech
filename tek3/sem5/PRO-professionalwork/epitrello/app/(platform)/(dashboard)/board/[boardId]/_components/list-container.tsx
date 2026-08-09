/* eslint-disable @typescript-eslint/no-explicit-any */
"use client";

import { ListWithCards } from "@/types";
import { ListForm } from "./list-form";
import { useEffect, useState } from "react";
import { ListItem } from "./list-item";
import { DragDropContext, Droppable } from "@hello-pangea/dnd";
import { useAction } from "@/hooks/use-action";
import { updateListOrder } from "@/actions/update-list-order";
import { updateCardOrder } from "@/actions/update-card-order";
import { toast } from "sonner";

interface ListContainerProps {
    data: ListWithCards[];
    boardId: string;
}

export const ListContainer = ({ data, boardId }: ListContainerProps) => {

    const [orderedData, setOrderedData] = useState(data);
    const { execute: executeUpdateListOrder } = useAction(updateListOrder, {
        onSuccess: () => {
            toast.success("List order updated");
            console.log("List order updated");
        },
        onError: () => {
            toast.error("Failed to update list order");
            console.log("Failed to update list order");
        },
     });
    const { execute: executeUpdateCardOrder } = useAction(updateCardOrder, {
        onSuccess: () => {
            toast.success("Card order updated");
            console.log("Card order updated");
        },
        onError: () => {
            toast.error("Failed to update card order");
            console.log("Failed to update card order");
        },
     });

    useEffect(() => {
        setOrderedData(data);
    }, [data]);

    function reorder<T>(list: T[], startIndex: number, endIndex: number): T[] {
        const result = Array.from(list);
        const [removed] = result.splice(startIndex, 1);
        result.splice(endIndex, 0, removed);
        return result;
    }

    const onDragEnd = (result: any) => {
        const { source, destination, type } = result;
        if (!destination) return;
        if (destination.droppableId === source.droppableId && destination.index === source.index) return;
        if (type === "list") {
            const items = reorder(orderedData, source.index, destination.index).map((list, index) => ({ ...list, order: index }));
            setOrderedData(items);
            executeUpdateListOrder({ items, boardId });
        }
        if (type === "card") {
            const newOrderedData = [...orderedData];

            const sourceList = newOrderedData.find((list) => list.id === source.droppableId);
            const destinationList = newOrderedData.find((list) => list.id === destination.droppableId);

            if (!sourceList || !destinationList) return;

            if (!sourceList.cards)
                sourceList.cards = [];
            if (!destinationList.cards)
                destinationList.cards = [];

            if (source.droppableId === destination.droppableId) {
                const items = reorder(sourceList.cards, source.index, destination.index);
                items.forEach((card, index) => { card.order = index });
                sourceList.cards = items;

                setOrderedData(newOrderedData);
                executeUpdateCardOrder({ items, boardId });

            } else {
                const [removed] = sourceList.cards.splice(source.index, 1);
                removed.listId = destination.droppableId;
                destinationList.cards.splice(destination.index, 0, removed);

                sourceList.cards.forEach((card, index) => { card.order = index });
                destinationList.cards.forEach((card, index) => { card.order = index });

                setOrderedData(newOrderedData);
                executeUpdateCardOrder({ boardId: boardId, items: destinationList.cards });
            }
        }
    }

    return (
        <DragDropContext onDragEnd={onDragEnd}>
            <Droppable droppableId="list" type="list" direction="horizontal">
                {(provided) => (
                <ol {...provided.droppableProps} ref={provided.innerRef} className="flex gap-x-3 h-full">
                    {orderedData.map((list, index) => (
                        <ListItem key={list.id} index={index} data={list} />
                    ))}
                    {provided.placeholder}
                    <ListForm />
                    <div className="flex-shrink-0 w-1"/>
                </ol>
                )}
            </Droppable>
        </DragDropContext>
    );
}
